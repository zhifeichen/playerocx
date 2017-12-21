function VideoComponent(container, id) {
    if(!(this instanceof VideoComponent)) {
        return new VideoComponent(container, id);
    }
    this.container = $('<div class="col-xs-4"> \
                            <div style="width: 100%; height: 100%; z-index: -1"><object></object></div> \
                            <div class="bxi-cover"> \
                                <p>浙江大学</p> \
                                <p>湖边-摄像头</p> \
                            </div> \
                            <div style="position: absolute; left: 15px; top: 0; width: 100%; height: 100%; z-index:100;"> \
                                <img src="./plugins/images/weather-bg.jpg"> \
                            </div> \
                        </div>');
    this.playerContainer = this.container.find('div:first');
    this.dName = this.container.find('.bxi-cover > p:first');
    this.cName = this.container.find('.bxi-cover > p:last');

    this.colClass = 'col-xs-4';
    this.isPlaying = false;
    this.id = id;

    $(container).append(this.container);
    this.container.height(Math.floor(this.container.width() * 3 / 4));

    var self = this;
    var img = this.container.find('img');
    img.width(this.container.width());
    img.height(this.container.height());
    this.container.find('img').contextmenu(function(){
        if(self.onclick){
            self.onclick(id);
        }
        return false;
    });
    this.click = function(cb) {
        if(cb){
            this.onclick = cb;
        }
    };
}

VideoComponent.prototype.setDName = function(name) {
    this.dName.text(name);
};

VideoComponent.prototype.setCName = function(name) {
    this.cName.text(name);
};

VideoComponent.prototype.setColClass = function(colClass) {
    if(colClass === this.colClass) {
        return;
    }
    this.container.removeClass(this.colClass);
    this.colClass = colClass;
    this.container.addClass(this.colClass);
    // this.container.height(Math.floor(this.container.width() * 3 / 4));
    
    // var img = this.container.find('img');
    // img.width(this.container.width());
    // img.height(this.container.height());
};

VideoComponent.prototype.adjustHeight = function(adjust) {
    var a = 0;
    if(adjust) a = 1;
    this.container.height(Math.floor(this.container.width() * 3 / 4) - a);
    var img = this.container.find('img');
    img.width(this.container.width());
    img.height(this.container.height());
};

VideoComponent.prototype.setVisible = function(visible) {
    if(!visible){
        this.container.addClass('dn');
    } else {
        this.container.removeClass('dn');
    }
}

VideoComponent.prototype.startPlay = function(config) {
    if(this.isPlaying) {
        this.stopPlay();
    }
    this.player = new Player(this.playerContainer,config);
    this.player.startPlay();
    this.isPlaying = true;
};

VideoComponent.prototype.stopPlay = function() {
    if(this.isPlaying) {
        this.player.stopPlay();
    }
};

VideoComponent.prototype.setActive = function(active) {
    if(active) {
        this.container.addClass('b-all panel-success');
    } else {
        this.container.removeClass('b-all panel-success');
    }
}
