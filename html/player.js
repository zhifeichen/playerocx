function Player(container, option) {
    if(!(this instanceof Player)) {
        return new Player(container, option);
    }
    hikPlayerHtml = '<object classid="clsid:872B31BA-01B5-4264-93E0-169d9C298C06" style="width: 100%; height: 100%"></object>';
    ezuPlayerHtml = '<object classid="clsid:54FC7795-1014-4BF6-8BA3-500C61EC1A05" style="width: 100%; height: 100%"></object>';
    if(!option.type || option.type === 0) { // hikPlayer
        container.find('object').replaceWith(hikPlayerHtml);

        this.type = 0;
        this.hikPlayer = container.find('object')[0];
        this.hikPlayer.Init();
        this.hikPlayer.HostIP = option.hostIP;
        this.hikPlayer.HostPort = option.hostPort;
        this.hikPlayer.Channel = option.channel;
        this.hikPlayer.UserName = option.userName;
        this.hikPlayer.Password = option.password;
    } else if(option.type === 1) { // ezuPlayer
        container.find('object').replaceWith(ezuPlayerHtml);

        this.type = 1;
        this.ezuPlayer = container.find('object')[0];
        this.ezuPlayer.InitWithAppKey(option.appKey);
        this.ezuPlayer.SetAccessToken(option.accessToken);
        this.ezuUrl = 'ezopen://open.ys7.com/' + option.device + '/' + option.channel + '.hd.live';
    }
}

Player.prototype.startPlay = function() {
    if(this.type === 0) { // hikPlayer
        this.hikPlayer.StartPlay();
    } else if(this.type === 1) { // ezuPlayer
        this.ezuPlayer.StartPlay(this.ezuUrl);
    }
}

Player.prototype.stopPlay = function() {
    if(this.type === 0) { // hikPlayer
        this.hikPlayer.StopPlay();
    } else if(this.type === 1) { // ezuPlayer
        this.ezuPlayer.StopPlay();
    }
}
