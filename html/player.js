function Player(container, option) {
    if(!(this instanceof Player)) {
        return new Player(container, option);
    }
    hikPlayerHtml = '<object classid="clsid:872b31ba-01b5-4264-93e0-169d9c298c06" style="width: 100%; height: 100%"></object>';
    ezuPlayerHtml = '<object classid="clsid:54FC7795-1014-4BF6-8BA3-500C61EC1A05" style="width: 100%; height: 100%"></object>';
    if(!option.type || option.type === 0) {
        container.innerHTML = hikPlayerHtml;

        this.hikPlayer = container.children[0];
        this.type = 0;
        this.hikPlayer.Init();
        this.hikPlayer.HostIP = option.hostIP;
        this.hikPlayer.HostPort = option.hostPort;
        this.hikPlayer.Channel = option.channel;
        this.hikPlayer.UserName = option.userName;
        this.hikPlayer.Password = option.password;
    } else if(option.type === 1) {
        container.innerHTML = ezuPlayerHtml;

        this.type = 1;
        this.ezuPlayer = container.children[0];
        this.ezuPlayer.InitWithAppKey(option.appKey);
        this.ezuPlayer.SetAccessToken(option.accessToken);
        this.ezuUrl = option.url;
    }
}

Player.prototype.startPlay = function() {
    if(this.type === 0) {
        this.hikPlayer.StartPlay();
    } else if(this.type === 1) {
        this.ezuPlayer.StartPlay(this.ezuUrl);
    }
}

Player.prototype.stopPlay = function() {
    if(this.type === 0) {
        this.hikPlayer.StopPlay();
        this.hikPlayer.Cleanup();
    } else if(this.type === 1) {
        this.ezuPlayer.StopPlay();
    }
}
