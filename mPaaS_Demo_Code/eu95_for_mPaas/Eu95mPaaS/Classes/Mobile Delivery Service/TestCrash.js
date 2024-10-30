require('AUNoticeDialog');
defineClass('MPMDSViewController', {
    createCrash: function() {
        var array = ["crash被Hotpacth热修复啦", "hello world"];
        var message = array[0];

        var alert = AUNoticeDialog.alloc().initWithTitle_message("提示", message);
        alert.addButton_actionBlock("知道了", block(function() {}));
        alert.show();
    },
});
