function VideoComponent(container) {
    if(!(this instanceof VideoComponent)) {
        return new VideoComponent(container);
    }
    this.container = $('<div class="col-xs-6 m-t-15 p-l-0 p-r-10"> \
                            <div style="width: 100%; height: 100%"><object></object></div> \
                            <div class="bxi-cover"> \
                                <p>浙江大学</p> \
                                <p>湖边-摄像头</p> \
                            </div> \
                        </div>');
    this.playerContainer = this.container.find('div:first');
    this.dName = this.container.find('.bxi-cover > p:first');
    this.cName = this.container.find('.bxi-cover > p:last');

    this.colClass = 'col-xs-6';

    $(container).append(this.container);
    this.container.height(this.container.width() * 3 / 4); 
}

VideoComponent.prototype.setDName = function(name) {
    this.dName.text(name);
};

VideoComponent.prototype.setCName = function(name) {
    this.cName.text(name);
};

VideoComponent.prototype.setColClass = function(colClass) {
    this.container.removeClass(this.colClass);
    this.colClass = colClass;
    this.container.addClass(this.colClass);
    this.container.height(this.container.width() * 3 / 4); 
};

VideoComponent.prototype.startPlay = function(config) {
    this.player = new Player(this.playerContainer,config);
    this.player.startPlay();
};

VideoComponent.prototype.stopPlay = function() {
    this.player.StopPlay();
};
