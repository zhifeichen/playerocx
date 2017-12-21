function VideoWall(container) {
    if(!(this instanceof VideoWall)) {
        return new VideoWall(container);
    }

    this.rows = [];

    for(var i = 0; i < 3; i++) {
        var row = $('<div class="row">');
        $(container).append(row);
        this.rows.push(row);
    }

    this.videos = [];
    this.layout = 9;
    this.current = 0;
    var self = this;
    this.setActive = function(id) {
        if(id === self.current) {
            return;
        }
        self.videos[self.current].setActive(false);
        self.current = id;
        self.videos[self.current].setActive(true);
    }
    for(var i = 0; i < 9; i++) {
        var video = new VideoComponent(this.rows[i/3>>0], i);
        video.click(this.setActive);
        this.videos.push(video);
    }
    this.videos[this.current].setActive(true);
}

VideoWall.prototype.setLayout = function(layout) {
    if(layout === 1) {
        for(var i = 0; i < 9; i++){
            if(i !== this.current){
                this.videos[i].setVisible(false);
                this.videos[this.current].setColClass('col-xs-12');
            }
            this.rows[2].append(this.videos[i].container);
        }
        this.layout = 1;
        this.videos[this.current].setColClass('col-xs-12');
        this.rows[0].append(this.videos[this.current].container);
    } else if(layout === 4) {
        for(var i = 0; i < 9; i++) {
            this.videos[i].setVisible(false);
            this.videos[i].setColClass('col-xs-6');
            this.rows[2].append(this.videos[i].container);
        }
        if(this.current > 3) {
            this.setActive(0); 
        }
        this.layout = 4;
        for(var i = 0; i < 4; i++) {
            this.videos[i].setVisible(true);
            this.rows[i/2>>0].append(this.videos[i].container);
        }
    } else if(layout === 9) {
        this.layout = 9;
        for(var i = 0; i < 9; i++) {
            this.videos[i].setVisible(true);
            this.videos[i].setColClass('col-xs-4');
            this.rows[i/3>>0].append(this.videos[i].container);
        }
    }
    for(var i = 0; i < 9; i++) {
        var a = i === 0
        this.videos[i].adjustHeight(a);
    }
};

VideoWall.prototype.startPlay = function(options) {
    this.videos[this.current].startPlay(options);
};

VideoWall.prototype.stopPlayAll = function() {
    this.videos.forEach(function(v){
        v.stopPlay();
    });
};

VideoWall.prototype.stopCurrentPlay = function() {
    	this.videos[this.current].stopPlay();
};
