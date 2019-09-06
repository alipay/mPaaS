(window.AlipayH5Performance && !window.AlipayCallFromJS) || (function(){
    var iframe = {};
    var sendMessageQueue={};
    var timerHandler={};
    function type(obj) {
        return Object.prototype.toString.call(obj).replace(/\[object (\w+)\]/, '$1').toLowerCase();
    }
    var monitorKernel={
        init:function(){
            this.init=null;
            this.renderIframe();
            this.monitorDOMReady();
            this.monitorPageLoad();
            this.monitorJSErrors();
            this.monitorDNSTime();
            this.monitorCacheRate();
            this.monitorMixedContent();
        },
        monitorDOMReady:function(){
            var t=this;
            var readyRE = /complete|loaded|interactive/;
            if (readyRE.test(document.readyState)) {
                t.pushMessage('monitor',{
                    name:'domReady',
                    value:new Date().getTime(),
                    extra:'completed'
                });
                t.sendSignal();
            } else {
                document.addEventListener("DOMContentLoaded", function(event) {
                    t.pushMessage('monitor',{
                        name:'domReady',
                        value:event.timeStamp?event.timeStamp:new Date().getTime(),
                        extra:'complete'
                    });
                    t.sendSignal();
                },true);
            }
        },
        monitorPageLoad:function(){
            var t=this;
            window.addEventListener("load", function(event) {
                t.pushMessage('monitor',{
                    name:'pageLoad',
                    value:event.timeStamp?event.timeStamp:new Date().getTime(),
                    extra:'load'
                });
                t.sendSignal();
            },true);
        },
        monitorJSErrors:function(){
            var t=this;
            window.addEventListener("error", function(event) {
                if (event.message) {
                    t.pushMessage('monitor',{
                                  name:'jsErrors',
                                  value:event.message,
                                  filename:event.filename,
                                  lineno:event.lineno,
                                  colno:event.colno
                                  });
                    t.sendSignal();
                }
            },true);
        },
        monitorDNSTime:function(){
            var t=this;
            window.addEventListener("load", function(event) {
                if(window.performance && window.performance.timing && window.performance.timing.domainLookupEnd-window){
                    t.pushMessage('monitor',{
                        name:'dns',
                        value:window.performance.timing.domainLookupEnd-window.performance.timing.domainLookupStart,
                        extra:'support'
                    });
                }else{
                    t.pushMessage('monitor',{
                        name:'dns',
                        value:'',
                        extra:'notsupport'
                    });
                }
                t.sendSignal();
            },true);
        },
        monitorMixedContent:function(){
            var t=this;
            var errorArr=[];
            var readyRE = /complete|loaded|interactive/;
            if (readyRE.test(document.readyState)) {
                window.location.protocol == 'https:' && [].slice.call(document.querySelectorAll('link[rel=stylesheet][href^="http:"], script[src^="http:"], img[src^="http:"]')).forEach(function (elem) {
                    errorArr.push(elem.tagName + ':' + (elem.src || elem.href));
                });
                if(errorArr.length>0){
                    t.pushMessage('monitor',{
                        name:'mixedContent',
                        value:errorArr.join('@|@')
                    });
                    t.sendSignal();
                }
            } else {
                document.addEventListener("DOMContentLoaded", function(event) {
                    window.location.protocol == 'https:' && [].slice.call(document.querySelectorAll('link[rel=stylesheet][href^="http:"], script[src^="http:"], img[src^="http:"]')).forEach(function (elem) {
                        errorArr.push(elem.tagName + ':' + (elem.src || elem.href));
                    });
                    if(errorArr.length>0){
                        t.pushMessage('monitor',{
                            name:'mixedContent',
                            value:errorArr.join('@|@')
                        });
                        t.sendSignal();
                    }
                },true);
            }
        },
        monitorCacheRate:function(){
            var t=this,
                result={
                    name:'cacheRate'
                },resourceArr;
            window.addEventListener("load", function(event) {
                if(window.performance && typeof window.performance.getEntriesByType ==='function' && (resourceArr=window.performance.getEntriesByType("resource"))){
                    if(resourceArr.length>0){
                        var cacheCount=0;
                        for(var i=0;i<resourceArr.length;i++){
                            if(resourceArr[i].duration===0){
                                cacheCount++;
                            }
                        }
                        result.value=(cacheCount/resourceArr.length).toFixed(4);

                    }else{
                        result.value=0.0000;
                    }
                    result.extra='support';
                }else{
                    result.value='';
                    result.extra='notsupport';
                }
                t.pushMessage('monitor',result);
                t.sendSignal();
            },true);
        },
        sendSignal:function(timer,tag){
            timer = (typeof timer=='number' &&timer>=0)?timer:500;
            tag = tag || 'monitor';
            clearTimeout(timerHandler[tag]);
            timerHandler[tag]=setTimeout(function(){
                if (!(iframe && iframe[tag])){
                    monitorKernel.renderIframe(tag);
                }
                iframe[tag].src='alipay'+tag.toLowerCase()+'://dispatch_'+tag.toLowerCase()+'_message';
            },timer);
        },
        renderIframe:function(tag) {
            tag = tag || 'monitor';
            if (iframe && iframe[tag]) return;
            try {
                var iframeElement = document.createElement("iframe");
                iframeElement.id = "__AlipayH5"+tag+"Iframe";
                iframeElement.style.display = "none";
                document.documentElement.appendChild(iframeElement);
                iframe[tag] = iframeElement;
            } catch (e) {}
        },
        pushMessage:function(tag,obj){
            tag = tag || 'monitor';
            if(!(sendMessageQueue && type(sendMessageQueue[tag]) == 'array')){
                sendMessageQueue[tag] = [];
            }
            sendMessageQueue[tag].push(obj);

        },
        getMessage:function(tag){
            tag = tag || 'monitor';
            if(!(sendMessageQueue && type(sendMessageQueue[tag]) == 'array')){
                sendMessageQueue[tag] = [];
            }
            var messageQueueString = JSON.stringify(sendMessageQueue[tag]);
            sendMessageQueue[tag] = [];
            return messageQueueString;

        }
    }
    monitorKernel.init();
    var monitorInterface={
        fetchMessageQueue: function (tag) {
            return monitorKernel.getMessage(tag);
        },
        reportBizReady: function(){
            monitorKernel.pushMessage('monitor',{name: 'availableTime',value: Date.now() + ''});
            monitorKernel.sendSignal(0);
        },
        pushMessage:function(tag,obj){
            monitorKernel.pushMessage(tag,obj);
        },
        addTrackData:function(obj,tag){
            tag = tag || 'monitor';
            if(obj.value){
                obj.value+=('|time='+new Date().getTime());
            }
            monitorKernel.pushMessage(tag,obj);
            monitorKernel.sendSignal(0);
        },
        addTimeReport:function(obj){
            var objStr = '';
            for(var item in obj){
                objStr += (((objStr=='')?'':'&')+item+'='+obj[item]);
            }
            monitorInterface.addTrackData({
                'name':'timeReport',
                'value':objStr
            });
        },
        sendSignal:function(tag){
            monitorKernel.renderIframe(tag);
            monitorKernel.sendSignal(0,tag);
        },
        version:'1.2'
    }
    window.AlipayH5Performance = monitorInterface;
})();
(window.AlipayH5Report && !window.AlipayCallFromJS) || (function(){
    var monitorInterface={
        fetchMessageQueue: function (tag) {
            return window.AlipayH5Performance.fetchMessageQueue('report');
        }
    }
    window.AlipayH5Report = monitorInterface;
})();
