/**
 * Created by xinnian on 2016/12/21.
 */
var setTimeout, setInterval, clearTimeout, clearInterval, AlipayTimersExecution;
if(!this.console){
  this.console = {
    log: function () {},
    error: function () {},
    warn: function () {},
    info: function () {}
  }
};
(function () {
  AlipayTimersExecution = {
    GUID: 1,
    Type: {
      setTimeout: "setTimeout",
      setInterval: "setInterval",
      requestAnimationFrame: "requestAnimationFrame",
      setImmediate: "setImmediate"
    },

    callbacks: [],
    types: [],
    timerIDs: [],
    immediates: [],

    callTimer: function (timerID) {

      var timerIndex = AlipayTimersExecution.timerIDs.indexOf(timerID);
      // timerIndex of -1 means that no timer with that ID exists. There are
      // two situations when this happens, when a garbage timer ID was given
      // and when a previously existing timer was deleted before this callback
      // fired. In both cases we want to ignore the timer id, but in the former
      // case we warn as well.
      if (timerIndex === -1) {
        return;
      }
      var type = AlipayTimersExecution.types[timerIndex];
      var callback = AlipayTimersExecution.callbacks[timerIndex];

      // Clear the metadata
      if (type === AlipayTimersExecution.Type.setTimeout || type === AlipayTimersExecution.Type.setImmediate || type === AlipayTimersExecution.Type.requestAnimationFrame) {
        AlipayTimersExecution._clearIndex(timerIndex);
      }

      try {
        if (type === AlipayTimersExecution.Type.setTimeout || type === AlipayTimersExecution.Type.setInterval || type === AlipayTimersExecution.Type.setImmediate) {
          callback();
        } else if (type === AlipayTimersExecution.Type.requestAnimationFrame) {
          var currentTime = performanceNow();
          callback(currentTime);
        } else {
          console.error('Tried to call a callback with invalid type: ' + type);
          return;
        }
      } catch (e) {
        // Don't rethrow so that we can run every other timer.
        AlipayTimersExecution.errors = AlipayTimersExecution.errors || [];
        AlipayTimersExecution.errors.push(e);
      }
    },

    /**
     * This is called from the native side. We are passed an array of timerIDs,
     * and
     */
    callTimers: function (timerIDs) {
      //invariant(timerIDs.length !== 0, 'Probably shouldn\'t call "callTimers" with no timerIDs');
      AlipayTimersExecution.errors = null;
      timerIDs.forEach(AlipayTimersExecution.callTimer);

      var errors = AlipayTimersExecution.errors;
      if (errors) {
        var errorCount = errors.length;
        if (errorCount > 1) {
          // Throw all the other errors in a setTimeout, which will throw each
          // error one at a time
          for (var ii = 1; ii < errorCount; ii++) {
            var error = errors[ii];
            AlipayTimers.setTimeout(function () {
                throw error;
              },
              0);
          }
        }
        throw errors[0];
      }
    },

    /**
     * This is called after we execute any command we receive from native but
     * before we hand control back to native.
     */
    callImmediates: function () {
      AlipayTimersExecution.errors = null;
      while (AlipayTimersExecution.immediates.length !== 0) {
        AlipayTimersExecution.callTimer(AlipayTimersExecution.immediates.shift());
      }
      if (AlipayTimersExecution.errors) {
        AlipayTimersExecution.errors.forEach(function () {
          var args = Array.prototype.slice.call(undefined, arguments);
          var error = args[0];
          AlipayTimers.setTimeout(function () {
              throw error;
            },
            0);
        });
      }
    },

    _clearIndex: function (i) {
      AlipayTimersExecution.timerIDs[i] = null;
      AlipayTimersExecution.callbacks[i] = null;
      AlipayTimersExecution.types[i] = null;
    }
  };

  function _getFreeIndex() {
    var freeIndex = AlipayTimersExecution.timerIDs.indexOf(null);
    if (freeIndex === -1) {
      freeIndex = AlipayTimersExecution.timerIDs.length;
    }
    return freeIndex;
  }

  function _allocateCallback(func, type) {
    const id = AlipayTimersExecution.GUID++;
    const freeIndex = _getFreeIndex();
    AlipayTimersExecution.timerIDs[freeIndex] = id;
    AlipayTimersExecution.callbacks[freeIndex] = func;
    AlipayTimersExecution.types[freeIndex] = type;
    return id;
  }

  function _freeCallback(timerID) {
    // AlipayTimersExecution.timerIDs contains nulls after timers have been removed;
    // ignore nulls upfront so indexOf doesn't find them
    if (timerID == null) {
      return;
    }

    var index = AlipayTimersExecution.timerIDs.indexOf(timerID);
    // See corresponding comment in `callTimers` for reasoning behind this
    if (index !== -1) {
      AlipayTimersExecution._clearIndex(index);
      const type = AlipayTimersExecution.types[index];
      if (type !== 'setImmediate' && type !== 'requestIdleCallback') {
        //call native method
        deleteTimer(timerID);
      }
    }
  }

  var AlipayTimers = {

    setTimeout: function () {
      var args = Array.prototype.slice.call(arguments);
      var func = arguments[0];
      var duration = arguments[1];

      var id = _allocateCallback((function (fn) {
        return function () {
          fn.apply(undefined, args.slice(2));
        }
      })(func), 'setTimeout');
      //call native method
      createTimer(id, duration || 0, Date.now(), false);
      return id;
    },

    setInterval: function () {
      var args = Array.prototype.slice.call(arguments);
      var func = arguments[0];
      var duration = arguments[1];

      var id = _allocateCallback((function (fn) {
        return function () {
          fn.apply(undefined, args.slice(2));
        }
      })(func), 'setInterval');
      //call native method
      createTimer(id, duration || 0, Date.now(), true);
      return id;
    },

    clearTimeout: function (timerID) {
      _freeCallback(timerID);
    },

    clearInterval: function (timerID) {
      _freeCallback(timerID);
    }
  };

  setTimeout = setTimeout || AlipayTimers.setTimeout;
  setInterval = setInterval || AlipayTimers.setInterval;
  clearTimeout = clearTimeout || AlipayTimers.clearTimeout;
  clearInterval = clearInterval || AlipayTimers.clearInterval;
})();



/**
 * Created by xinnian on 2016/11/24.
 */
var document, AlipayJSBridge, window, self = {};
// window self 指向global 对象
window = self = this;
(function () {
  //set global nativeFlushQueueImmediate  null
  var nativeFlushQueueImmediate = this.nativeFlushQueueImmediate;
  this.nativeFlushQueueImmediate = null;

  var handlers = {};
  var windowHanders = {};
  var sendMessageQueue = [];

  function Event(name) {
    this.name = name;
  }

  Event.prototype = {
    preventDefault: function () {
      this._preventDefault = true;
    },
    initEvent: function(name) {
      this.name = name;
    },
    isDefaultPrevented: function () {
      return !!this._preventDefault;
    }
  };
  function add(eventName, fn) {
    handlers[eventName] || (handlers[eventName] = []);

    var handler = {};
    handler.fn = fn;

    handlers[eventName].push(handler);
  }

  function windowAddEvent(eventName, fn) {
    windowHanders[eventName] || (windowHanders[eventName] = []);

    var handler = {};
    handler.fn = fn;

    windowHanders[eventName].push(handler);
  }

  function remove(eventName, fn) {
    if (handlers[eventName]) {
      for (var i = 0; i < handlers[eventName].length; i++) {
        if (fn === handlers[eventName][i].fn) {
          handlers[eventName].splice(i, 1);
          if (handlers[eventName].length === 0) {
            delete handlers[eventName];
          }
          break;
        }
      }
    }
  }

  function removeWindowEvent(eventName, fn) {
    if (windowHanders[eventName]) {
      for (var i = 0; i < windowHanders[eventName].length; i++) {
        if (fn === windowHanders[eventName][i].fn) {
          windowHanders[eventName].splice(i, 1);
          if (windowHanders[eventName].length === 0) {
            delete windowHanders[eventName];
          }
          break;
        }
      }
    }
  }

  function createEvent(eventName) {
    return new Event(eventName);
  }

  function dispatchEvent(eventName, args) {
    var evt = createEvent(eventName);
    var isDefaultPrevented = false;
    if (handlers[eventName]) {
      for (var i = 0; i < handlers[eventName].length; i++) {
        evt.data = args;
        handlers[eventName][i].fn(evt);
        if (evt.isDefaultPrevented()) {
          isDefaultPrevented = true;
        }
      }
    }

    return !isDefaultPrevented;
  }

  function trigger(eventName, args) {

        var isDefaultPrevented = !dispatchEvent(eventName, args);
        if (args.callbackId) {
            var callbackData = {};
            callbackData.callbackId = args.callbackId;
            callbackData[eventName + 'EventCanceled'] = isDefaultPrevented;
            if (typeof args["func"] === "string") {
                callbackData[args["func"] + 'EventCanceled'] = isDefaultPrevented;
            }
            AlipayJSBridge.call("__nofunc__",callbackData);
            // delete args.callbackId;
        }
  }

  document = {
    addEventListener: add,
    removeEventListener: remove,
    trigger: trigger,
    sendMessageQueue: sendMessageQueue,
    createEvent: createEvent,
    dispatchEvent: dispatchEvent,
    location: {
      href: 'about:blank',
        toString:function () {
            return location.href;
        }
    },

    title: ''
  };
  window.addEventListener = windowAddEvent;
  window.removeEventListener = removeWindowEvent;
  var msgPortMap = {};

  function trasMsgPort(viewId, pageId, msgPort) {
    msgPort.postMessage = function (data) {
      var _data = {
        data: data,
        type: 'messagePort',
        msgPortId: msgPort.id,
        viewId: viewId,
        pageId: pageId
      };
      AlipayJSBridge.call("postMessage", _data);
    };
    if(!msgPortMap['m_'+viewId]){
      msgPortMap['m_'+viewId] = {};
    }
    if(!msgPortMap['m_' + viewId]['p_' + pageId]){
      msgPortMap['m_' + viewId]['p_' + pageId] = {};
    }
    msgPortMap['m_'+viewId]['p_' + pageId][msgPort.id] = msgPort;
    return msgPort;
  }

  document.addEventListener('message', function (event) {
    if (event.data && event.data.type != 'messagePort' && !event.data.beforeunload) {
      var data = event.data.data;
      var eventPorts = event.data.eventPorts;
      var viewId = event.data.viewId;
      var pageId = event.data.pageId || 0;
      if (eventPorts && eventPorts[0]) {
        eventPorts[0] = trasMsgPort(viewId, pageId, eventPorts[0]);
      }
      if (windowHanders['message']) {
        for (var i = 0; i < windowHanders['message'].length; i++) {
          event.data = data;
          event.ports = eventPorts;
          windowHanders['message'][i].fn(event);
        }
      }
    } else if (event.data && event.data.type == 'messagePort' && event.data.msgPortId) {
      var viewId = event.data.viewId;
      var pageId = event.data.pageId || 0;
      if(!msgPortMap['m_' + viewId] || !msgPortMap['m_' + viewId]['p_' + pageId]){
        console.error('unknown view', event, msgPortMap);
        return;
      }
      var msgPort = msgPortMap['m_' + viewId]['p_' + pageId][event.data.msgPortId];
      if (msgPort && msgPort.onmessage) {
        msgPort.onmessage({
          data: event.data.data
        });
      }
    }  else {
      console.log('unknown event', event);
    }
  });

  Object.defineProperty(document.location, "href", {
    get: function () {
      return document.location._href;
    },

    set: function (newValue) {
      if (typeof newValue !== 'string') return;

      newValue = newValue.trim();
      if(self.AlipayJSBridge._trimLocationHref){
        var rs = self.AlipayJSBridge._trimLocationHref(newValue);
        if(rs){
          for(var key in rs){
            if(key != "href" && typeof rs[key] !== "function"){
                document.location[key] = rs[key];
            }
          }
        }
      }
      document.location._href = newValue;
    }
  });
    /***************Param Type*****************/
    var NEBULA_TYPE_INFO = "NEBULATYPEINFO",NEBULA_TYPE_OF_ARRAYBUFFER = "ArrayBuffer";


    var chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    var lookup = new Uint8Array(256);
    for (var i = 0; i < chars.length; i++) {
        lookup[chars.charCodeAt(i)] = i;
    }
    
    function arrayBufferToBase64(arraybuffer) {
        var bytes = new Uint8Array(arraybuffer),
        i, len = bytes.length, base64 = "";

        for (i = 0; i < len; i+=3) {
          base64 += chars[bytes[i] >> 2];
          base64 += chars[((bytes[i] & 3) << 4) | (bytes[i + 1] >> 4)];
          base64 += chars[((bytes[i + 1] & 15) << 2) | (bytes[i + 2] >> 6)];
          base64 += chars[bytes[i + 2] & 63];
        }

        if ((len % 3) === 2) {
          base64 = base64.substring(0, base64.length - 1) + "=";
        } else if (len % 3 === 1) {
          base64 = base64.substring(0, base64.length - 2) + "==";
        }

        return base64;
    }

    function base64ToArrayBuffer(base64) {
        var bufferLength = base64.length * 0.75,
        len = base64.length, i, p = 0,
        encoded1, encoded2, encoded3, encoded4;

        if (base64[base64.length - 1] === "=") {
          bufferLength--;
          if (base64[base64.length - 2] === "=") {
            bufferLength--;
          }
        }

        var arraybuffer = new ArrayBuffer(bufferLength),
        bytes = new Uint8Array(arraybuffer);

        for (i = 0; i < len; i+=4) {
          encoded1 = lookup[base64.charCodeAt(i)];
          encoded2 = lookup[base64.charCodeAt(i+1)];
          encoded3 = lookup[base64.charCodeAt(i+2)];
          encoded4 = lookup[base64.charCodeAt(i+3)];

          bytes[p++] = (encoded1 << 2) | (encoded2 >> 4);
          bytes[p++] = ((encoded2 & 15) << 4) | (encoded3 >> 2);
          bytes[p++] = ((encoded3 & 3) << 6) | (encoded4 & 63);
        }

        return arraybuffer;
    }

    function transformCallParam(param){
        var result = param;
        for(var key in param){
            if (param.hasOwnProperty(key)) {
                var val = param[key];
                if (val instanceof ArrayBuffer) {
                    param[key] = arrayBufferToBase64(val);
                    if (!result[NEBULA_TYPE_INFO]) {
                        result[NEBULA_TYPE_INFO] = {};
                    }
                    result[NEBULA_TYPE_INFO][key] = {"type" : NEBULA_TYPE_OF_ARRAYBUFFER};
                }
            }
        }
        return result;
    }

    function transformResponseData(responsedata){
        if(responsedata && responsedata[NEBULA_TYPE_INFO]){
            var nebulaTypeInfo = responsedata[NEBULA_TYPE_INFO];
            if (nebulaTypeInfo) {
                for(var key in nebulaTypeInfo){
                    if (nebulaTypeInfo.hasOwnProperty(key)) {
                        var item = nebulaTypeInfo[key];
                        if (item.type) {
                            var typeVal = item["type"];
                            if (typeVal === NEBULA_TYPE_OF_ARRAYBUFFER) {
                                responsedata[key] = base64ToArrayBuffer(responsedata[key]);
                            }
                        }
                    }
                }
            }
        }
        return responsedata;
    }

  var callbackPoll = [];

  AlipayJSBridge = {

    call: function (func, param, callback) {

      if ('string' !== typeof func) {
        return;
      }

      if ('function' === typeof param) {
        callback = param;
        param = null;
      } else if (typeof param !== 'object') {
        param = null;
      }

      var callbackId = func + '_' + new Date().getTime() + (Math.random());
      if ('function' === typeof callback) {
        callbackPoll[callbackId] = callback;
      }

      if (param && param.callbackId) {
        func = {
          responseId: param.callbackId,
          responseData: param
        };
        delete param.callbackId;
      } else {
       var dataJson = transformCallParam(param),targetData;
        try{
          targetData = JSON.stringify(dataJson);
        }catch(ex){
          console.log(ex);
          targetData = JSON.stringify({});
        }
        func = {
          handlerName: func,
          data: targetData || {}
        };
        func.callbackId = '' + callbackId;
      }
      nativeFlushQueueImmediate([func]);
    },

    _handleMessageFromObjC: function (message) {
      var resp = JSON.parse(message);
      var handlerName = resp.handlerName;
      var data = resp.data;
      data || (data = {});
      data.callbackId = resp.callbackId;
      // setTimeout(function() {
      //document.trigger(handlerName, data);
      AlipayJSBridge._invokeJS(resp);
      // },1);
    },

    _invokeJS: function (resp) {
      if (resp.responseId) {
        var func = callbackPoll[resp.responseId];
        if (!(typeof resp.keepCallback == 'boolean' && resp.keepCallback)) {
          delete callbackPoll[resp.responseId];
        }

        if ('function' === typeof func) {
          func(transformResponseData(resp.responseData));
        }
      } else if (resp.handlerName) {
        if (resp.callbackId) {
          resp.data = resp.data || {};
          resp.data.callbackId = resp.callbackId;
        }
        document.trigger(resp.handlerName, resp.data);
      }
    },

    _fetchQueue: function () {
      var messageQueueString = JSON.stringify(document.sendMessageQueue);
      document.sendMessageQueue.length = 0;
      return messageQueueString;
    },

    _domReady: function () {
      GLOBAL.ALIPAYH5STARTUPPARAMS || {};
      GLOBAL.ALIPAYH5STARTUPPARAMS = null;
      document.dispatchEvent('DOMContentLoaded', null);
      document.dispatchEvent('AlipayJSBridgeReady', null);
    }
  };

  window.history = {
    length: 1
  };

  window.location = document.location;
  window.document = document;
})();!function(t){function e(s){if(r[s])return r[s].exports;var n=r[s]={exports:{},id:s,loaded:!1};return t[s].call(n.exports,n,n.exports,e),n.loaded=!0,n.exports}var r={};return e.m=t,e.c=r,e.p="",e(0)}({0:function(t,e,r){"use strict";function s(t){return t&&t.__esModule?t:{default:t}}var n=r(73),o=s(n),h=r(66),a=s(h);window.importScripts=o.default;var i={};if(self.navigator&&(self.navigator.userAgent||self.navigator.swuserAgent)){var l=self.navigator.userAgent||self.navigator.swuserAgent,u=l.match(/\sOS\s\d*_\d*/gi);if(u&&u.length>0){var c=u[0],f=c.match(/\d+/gi);i.version=parseInt(f[0]),i.subVersion=parseInt(f[1])}}self.Promise&&(self.sourcePromise=self.Promise);try{self.Promise=null,(0,o.default)("https://as.alipayobjects.com/g/component/es6-promise/3.2.2/es6-promise.min.js")}catch(t){console.error("加载Promise 出错::",t),self.Promise=self.sourcePromise}self&&self.AlipayJSBridge&&(self.AlipayJSBridge._trimLocationHref=function(t){var e={href:t};try{e=a.default.parse(t),e&&!e.origin&&(e.origin=e.protocol+"//"+e.host),["hash","search","query"].forEach(function(t){null===e[t]&&(e[t]="")});for(var r in e)"function"==typeof e[r]&&delete e[r]}catch(t){console.error("url 解析错误:",t)}return e})},66:function(t,e,r){"use strict";function s(){this.protocol=null,this.slashes=null,this.auth=null,this.host=null,this.port=null,this.hostname=null,this.hash=null,this.search=null,this.query=null,this.pathname=null,this.path=null,this.href=null}function n(t,e,r){if(t&&l.isObject(t)&&t instanceof s)return t;var n=new s;return n.parse(t,e,r),n}function o(t){return l.isString(t)&&(t=n(t)),t instanceof s?t.format():s.prototype.format.call(t)}function h(t,e){return n(t,!1,!0).resolve(e)}function a(t,e){return t?n(t,!1,!0).resolveObject(e):e}var i=r(67),l=r(69);e.parse=n,e.resolve=h,e.resolveObject=a,e.format=o,e.Url=s;var u=/^([a-z0-9.+-]+:)/i,c=/:[0-9]*$/,f=/^(\/\/?(?!\/)[^\?\s]*)(\?[^\s]*)?$/,p=["<",">",'"',"`"," ","\r","\n","\t"],m=["{","}","|","\\","^","`"].concat(p),v=["'"].concat(m),d=["%","/","?",";","#"].concat(v),g=["/","?","#"],y=255,b=/^[+a-z0-9A-Z_-]{0,63}$/,x=/^([+a-z0-9A-Z_-]{0,63})(.*)$/,j={javascript:!0,"javascript:":!0},O={javascript:!0,"javascript:":!0},w={http:!0,https:!0,ftp:!0,gopher:!0,file:!0,"http:":!0,"https:":!0,"ftp:":!0,"gopher:":!0,"file:":!0},A=r(70);s.prototype.parse=function(t,e,r){if(!l.isString(t))throw new TypeError("Parameter 'url' must be a string, not "+typeof t);var s=t.indexOf("?"),n=s!==-1&&s<t.indexOf("#")?"?":"#",o=t.split(n),h=/\\/g;o[0]=o[0].replace(h,"/"),t=o.join(n);var a=t;if(a=a.trim(),!r&&1===t.split("#").length){var c=f.exec(a);if(c)return this.path=a,this.href=a,this.pathname=c[1],c[2]?(this.search=c[2],e?this.query=A.parse(this.search.substr(1)):this.query=this.search.substr(1)):e&&(this.search="",this.query={}),this}var p=u.exec(a);if(p){p=p[0];var m=p.toLowerCase();this.protocol=m,a=a.substr(p.length)}if(r||p||a.match(/^\/\/[^@\/]+@[^@\/]+/)){var C="//"===a.substr(0,2);!C||p&&O[p]||(a=a.substr(2),this.slashes=!0)}if(!O[p]&&(C||p&&!w[p])){for(var I=-1,q=0;q<g.length;q++){var U=a.indexOf(g[q]);U!==-1&&(I===-1||U<I)&&(I=U)}var R,S;S=I===-1?a.lastIndexOf("@"):a.lastIndexOf("@",I),S!==-1&&(R=a.slice(0,S),a=a.slice(S+1),this.auth=decodeURIComponent(R)),I=-1;for(var q=0;q<d.length;q++){var U=a.indexOf(d[q]);U!==-1&&(I===-1||U<I)&&(I=U)}I===-1&&(I=a.length),this.host=a.slice(0,I),a=a.slice(I),this.parseHost(),this.hostname=this.hostname||"";var P="["===this.hostname[0]&&"]"===this.hostname[this.hostname.length-1];if(!P)for(var k=this.hostname.split(/\./),q=0,E=k.length;q<E;q++){var _=k[q];if(_&&!_.match(b)){for(var N="",F=0,L=_.length;F<L;F++)N+=_.charCodeAt(F)>127?"x":_[F];if(!N.match(b)){var $=k.slice(0,q),z=k.slice(q+1),H=_.match(x);H&&($.push(H[1]),z.unshift(H[2])),z.length&&(a="/"+z.join(".")+a),this.hostname=$.join(".");break}}}this.hostname.length>y?this.hostname="":this.hostname=this.hostname.toLowerCase(),P||(this.hostname=i.toASCII(this.hostname));var M=this.port?":"+this.port:"",T=this.hostname||"";this.host=T+M,this.href+=this.host,P&&(this.hostname=this.hostname.substr(1,this.hostname.length-2),"/"!==a[0]&&(a="/"+a))}if(!j[m])for(var q=0,E=v.length;q<E;q++){var B=v[q];if(a.indexOf(B)!==-1){var J=encodeURIComponent(B);J===B&&(J=escape(B)),a=a.split(B).join(J)}}var K=a.indexOf("#");K!==-1&&(this.hash=a.substr(K),a=a.slice(0,K));var Z=a.indexOf("?");if(Z!==-1?(this.search=a.substr(Z),this.query=a.substr(Z+1),e&&(this.query=A.parse(this.query)),a=a.slice(0,Z)):e&&(this.search="",this.query={}),a&&(this.pathname=a),w[m]&&this.hostname&&!this.pathname&&(this.pathname="/"),this.pathname||this.search){var M=this.pathname||"",V=this.search||"";this.path=M+V}return this.href=this.format(),this},s.prototype.format=function(){var t=this.auth||"";t&&(t=encodeURIComponent(t),t=t.replace(/%3A/i,":"),t+="@");var e=this.protocol||"",r=this.pathname||"",s=this.hash||"",n=!1,o="";this.host?n=t+this.host:this.hostname&&(n=t+(this.hostname.indexOf(":")===-1?this.hostname:"["+this.hostname+"]"),this.port&&(n+=":"+this.port)),this.query&&l.isObject(this.query)&&Object.keys(this.query).length&&(o=A.stringify(this.query));var h=this.search||o&&"?"+o||"";return e&&":"!==e.substr(-1)&&(e+=":"),this.slashes||(!e||w[e])&&n!==!1?(n="//"+(n||""),r&&"/"!==r.charAt(0)&&(r="/"+r)):n||(n=""),s&&"#"!==s.charAt(0)&&(s="#"+s),h&&"?"!==h.charAt(0)&&(h="?"+h),r=r.replace(/[?#]/g,function(t){return encodeURIComponent(t)}),h=h.replace("#","%23"),e+n+r+h+s},s.prototype.resolve=function(t){return this.resolveObject(n(t,!1,!0)).format()},s.prototype.resolveObject=function(t){if(l.isString(t)){var e=new s;e.parse(t,!1,!0),t=e}for(var r=new s,n=Object.keys(this),o=0;o<n.length;o++){var h=n[o];r[h]=this[h]}if(r.hash=t.hash,""===t.href)return r.href=r.format(),r;if(t.slashes&&!t.protocol){for(var a=Object.keys(t),i=0;i<a.length;i++){var u=a[i];"protocol"!==u&&(r[u]=t[u])}return w[r.protocol]&&r.hostname&&!r.pathname&&(r.path=r.pathname="/"),r.href=r.format(),r}if(t.protocol&&t.protocol!==r.protocol){if(!w[t.protocol]){for(var c=Object.keys(t),f=0;f<c.length;f++){var p=c[f];r[p]=t[p]}return r.href=r.format(),r}if(r.protocol=t.protocol,t.host||O[t.protocol])r.pathname=t.pathname;else{for(var m=(t.pathname||"").split("/");m.length&&!(t.host=m.shift()););t.host||(t.host=""),t.hostname||(t.hostname=""),""!==m[0]&&m.unshift(""),m.length<2&&m.unshift(""),r.pathname=m.join("/")}if(r.search=t.search,r.query=t.query,r.host=t.host||"",r.auth=t.auth,r.hostname=t.hostname||t.host,r.port=t.port,r.pathname||r.search){var v=r.pathname||"",d=r.search||"";r.path=v+d}return r.slashes=r.slashes||t.slashes,r.href=r.format(),r}var g=r.pathname&&"/"===r.pathname.charAt(0),y=t.host||t.pathname&&"/"===t.pathname.charAt(0),b=y||g||r.host&&t.pathname,x=b,j=r.pathname&&r.pathname.split("/")||[],m=t.pathname&&t.pathname.split("/")||[],A=r.protocol&&!w[r.protocol];if(A&&(r.hostname="",r.port=null,r.host&&(""===j[0]?j[0]=r.host:j.unshift(r.host)),r.host="",t.protocol&&(t.hostname=null,t.port=null,t.host&&(""===m[0]?m[0]=t.host:m.unshift(t.host)),t.host=null),b=b&&(""===m[0]||""===j[0])),y)r.host=t.host||""===t.host?t.host:r.host,r.hostname=t.hostname||""===t.hostname?t.hostname:r.hostname,r.search=t.search,r.query=t.query,j=m;else if(m.length)j||(j=[]),j.pop(),j=j.concat(m),r.search=t.search,r.query=t.query;else if(!l.isNullOrUndefined(t.search)){if(A){r.hostname=r.host=j.shift();var C=!!(r.host&&r.host.indexOf("@")>0)&&r.host.split("@");C&&(r.auth=C.shift(),r.host=r.hostname=C.shift())}return r.search=t.search,r.query=t.query,l.isNull(r.pathname)&&l.isNull(r.search)||(r.path=(r.pathname?r.pathname:"")+(r.search?r.search:"")),r.href=r.format(),r}if(!j.length)return r.pathname=null,r.search?r.path="/"+r.search:r.path=null,r.href=r.format(),r;for(var I=j.slice(-1)[0],q=(r.host||t.host||j.length>1)&&("."===I||".."===I)||""===I,U=0,R=j.length;R>=0;R--)I=j[R],"."===I?j.splice(R,1):".."===I?(j.splice(R,1),U++):U&&(j.splice(R,1),U--);if(!b&&!x)for(;U--;U)j.unshift("..");!b||""===j[0]||j[0]&&"/"===j[0].charAt(0)||j.unshift(""),q&&"/"!==j.join("/").substr(-1)&&j.push("");var S=""===j[0]||j[0]&&"/"===j[0].charAt(0);if(A){r.hostname=r.host=S?"":j.length?j.shift():"";var C=!!(r.host&&r.host.indexOf("@")>0)&&r.host.split("@");C&&(r.auth=C.shift(),r.host=r.hostname=C.shift())}return b=b||r.host&&j.length,b&&!S&&j.unshift(""),j.length?r.pathname=j.join("/"):(r.pathname=null,r.path=null),l.isNull(r.pathname)&&l.isNull(r.search)||(r.path=(r.pathname?r.pathname:"")+(r.search?r.search:"")),r.auth=t.auth||r.auth,r.slashes=r.slashes||t.slashes,r.href=r.format(),r},s.prototype.parseHost=function(){var t=this.host,e=c.exec(t);e&&(e=e[0],":"!==e&&(this.port=e.substr(1)),t=t.substr(0,t.length-e.length)),t&&(this.hostname=t)}},67:function(t,e,r){var s;(function(t,n){!function(o){function h(t){throw RangeError(k[t])}function a(t,e){for(var r=t.length,s=[];r--;)s[r]=e(t[r]);return s}function i(t,e){var r=t.split("@"),s="";r.length>1&&(s=r[0]+"@",t=r[1]),t=t.replace(P,".");var n=t.split("."),o=a(n,e).join(".");return s+o}function l(t){for(var e,r,s=[],n=0,o=t.length;n<o;)e=t.charCodeAt(n++),e>=55296&&e<=56319&&n<o?(r=t.charCodeAt(n++),56320==(64512&r)?s.push(((1023&e)<<10)+(1023&r)+65536):(s.push(e),n--)):s.push(e);return s}function u(t){return a(t,function(t){var e="";return t>65535&&(t-=65536,e+=N(t>>>10&1023|55296),t=56320|1023&t),e+=N(t)}).join("")}function c(t){return t-48<10?t-22:t-65<26?t-65:t-97<26?t-97:j}function f(t,e){return t+22+75*(t<26)-((0!=e)<<5)}function p(t,e,r){var s=0;for(t=r?_(t/C):t>>1,t+=_(t/e);t>E*w>>1;s+=j)t=_(t/E);return _(s+(E+1)*t/(t+A))}function m(t){var e,r,s,n,o,a,i,l,f,m,v=[],d=t.length,g=0,y=q,b=I;for(r=t.lastIndexOf(U),r<0&&(r=0),s=0;s<r;++s)t.charCodeAt(s)>=128&&h("not-basic"),v.push(t.charCodeAt(s));for(n=r>0?r+1:0;n<d;){for(o=g,a=1,i=j;n>=d&&h("invalid-input"),l=c(t.charCodeAt(n++)),(l>=j||l>_((x-g)/a))&&h("overflow"),g+=l*a,f=i<=b?O:i>=b+w?w:i-b,!(l<f);i+=j)m=j-f,a>_(x/m)&&h("overflow"),a*=m;e=v.length+1,b=p(g-o,e,0==o),_(g/e)>x-y&&h("overflow"),y+=_(g/e),g%=e,v.splice(g++,0,y)}return u(v)}function v(t){var e,r,s,n,o,a,i,u,c,m,v,d,g,y,b,A=[];for(t=l(t),d=t.length,e=q,r=0,o=I,a=0;a<d;++a)v=t[a],v<128&&A.push(N(v));for(s=n=A.length,n&&A.push(U);s<d;){for(i=x,a=0;a<d;++a)v=t[a],v>=e&&v<i&&(i=v);for(g=s+1,i-e>_((x-r)/g)&&h("overflow"),r+=(i-e)*g,e=i,a=0;a<d;++a)if(v=t[a],v<e&&++r>x&&h("overflow"),v==e){for(u=r,c=j;m=c<=o?O:c>=o+w?w:c-o,!(u<m);c+=j)b=u-m,y=j-m,A.push(N(f(m+b%y,0))),u=_(b/y);A.push(N(f(u,0))),o=p(r,g,s==n),r=0,++s}++r,++e}return A.join("")}function d(t){return i(t,function(t){return R.test(t)?m(t.slice(4).toLowerCase()):t})}function g(t){return i(t,function(t){return S.test(t)?"xn--"+v(t):t})}var y=("object"==typeof e&&e&&!e.nodeType&&e,"object"==typeof t&&t&&!t.nodeType&&t,"object"==typeof n&&n);y.global!==y&&y.window!==y&&y.self!==y||(o=y);var b,x=2147483647,j=36,O=1,w=26,A=38,C=700,I=72,q=128,U="-",R=/^xn--/,S=/[^\x20-\x7E]/,P=/[\x2E\u3002\uFF0E\uFF61]/g,k={overflow:"Overflow: input needs wider integers to process","not-basic":"Illegal input >= 0x80 (not a basic code point)","invalid-input":"Invalid input"},E=j-O,_=Math.floor,N=String.fromCharCode;b={version:"1.3.2",ucs2:{decode:l,encode:u},decode:m,encode:v,toASCII:g,toUnicode:d},s=function(){return b}.call(e,r,e,t),!(void 0!==s&&(t.exports=s))}(this)}).call(e,r(68)(t),function(){return this}())},68:function(t,e){t.exports=function(t){return t.webpackPolyfill||(t.deprecate=function(){},t.paths=[],t.children=[],t.webpackPolyfill=1),t}},69:function(t,e){"use strict";t.exports={isString:function(t){return"string"==typeof t},isObject:function(t){return"object"==typeof t&&null!==t},isNull:function(t){return null===t},isNullOrUndefined:function(t){return null==t}}},70:function(t,e,r){"use strict";e.decode=e.parse=r(71),e.encode=e.stringify=r(72)},71:function(t,e){"use strict";function r(t,e){return Object.prototype.hasOwnProperty.call(t,e)}t.exports=function(t,e,s,n){e=e||"&",s=s||"=";var o={};if("string"!=typeof t||0===t.length)return o;var h=/\+/g;t=t.split(e);var a=1e3;n&&"number"==typeof n.maxKeys&&(a=n.maxKeys);var i=t.length;a>0&&i>a&&(i=a);for(var l=0;l<i;++l){var u,c,f,p,m=t[l].replace(h,"%20"),v=m.indexOf(s);v>=0?(u=m.substr(0,v),c=m.substr(v+1)):(u=m,c=""),f=decodeURIComponent(u),p=decodeURIComponent(c),r(o,f)?Array.isArray(o[f])?o[f].push(p):o[f]=[o[f],p]:o[f]=p}return o}},72:function(t,e){"use strict";var r=function(t){switch(typeof t){case"string":return t;case"boolean":return t?"true":"false";case"number":return isFinite(t)?t:"";default:return""}};t.exports=function(t,e,s,n){return e=e||"&",s=s||"=",null===t&&(t=void 0),"object"==typeof t?Object.keys(t).map(function(n){var o=encodeURIComponent(r(n))+s;return Array.isArray(t[n])?t[n].map(function(t){return o+encodeURIComponent(r(t))}).join(e):o+encodeURIComponent(r(t[n]))}).join(e):n?encodeURIComponent(r(n))+s+encodeURIComponent(r(t)):""}},73:function(t,e,r){"use strict";function s(t){return t&&t.__esModule?t:{default:t}}function n(t){if(arguments&&arguments.length>1)for(var e=0,r=arguments.length;e<r;e++)n(arguments[e]);else{t.search(/^http(s)*:\/\//gi)==-1&&(t=h.default.resolve(location.href,t));var s=a(t);if(!s)throw new Error("import script Error")}}var o=r(66),h=s(o),a=self.importScript;t.exports=n}});
//set importScript null 
this.importScript = null;
