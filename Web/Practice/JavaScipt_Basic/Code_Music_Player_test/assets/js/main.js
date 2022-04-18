/*
1. Render songs
2. Scroll top
3. Play / pause / seek
4. CD rotate
5. Next / prev
6. Random
7. Next / Repeat when ended
8. Active song
9. Scroll active song into view
10. Play song when click
 */

const $ = document.querySelector.bind(document);
const $$ = document.querySelectorAll.bind(document);

const PlAYER_STORAGE_KEY = "F8_PLAYER";

const playlist = $('.playlist');
const image = $('.image');
const headerH2 = $('header h2');
const imageSong = $('.image-cd');
const audio = $('#audio');
const player = $('.player');
const playBtn = $('.btn-play');
const pauseBtn = $('.btn-pause');
const progress = $('#progress');
const forwardBtn = $('.btn-forward');
const backwardBtn = $('.btn-backward');
const randomBtn = $('.btn-random');
const redoBtn = $('.btn-redo');




const app = {
    currentIndex : 0,
    isRandom : false,
    isRepeat : false,
    // config: {},
      // (1/2) Uncomment the line below to use localStorage
    config: JSON.parse(localStorage.getItem(PlAYER_STORAGE_KEY)) || {},
    songs : [
        {
            name: 'Song 1',
            singer: 'Author 1',
            path: './assets/music/song1.mp3',
            image: './assets/img/image1.jpeg'
        }, 
        {
            name: 'Song 2',
            singer: 'Author 2',
            path: './assets/music/song2.mp3',
            image: './assets/img/image2.jpeg'
        }, 
        {
            name: 'Song 3',
            singer: 'Author 3',
            path: './assets/music/song3.mp3',
            image: './assets/img/image3.jpeg'
        }, 
        {
            name: 'Song 4',
            singer: 'Author 4',
            path: './assets/music/song4.mp3',
            image: './assets/img/image4.jpeg'
        }, 
        {
            name: 'Song 5',
            singer: 'Author 5',
            path: './assets/music/song5.mp3',
            image: './assets/img/image5.jpeg'
        }, 
        {
            name: 'Song 6',
            singer: 'Author 6',
            path: './assets/music/song6.mp3',
            image: './assets/img/image6.jpeg'
        }, 
        {
            name: 'Song 7',
            singer: 'Author 7',
            path: './assets/music/song7.mp3',
            image: './assets/img/image7.jpeg'
        }, 
        {
            name: 'Song 8',
            singer: 'Author 8',
            path: './assets/music/song8.mp3',
            image: './assets/img/image8.jpeg'
        }, 
        {
            name: 'Song 9',
            singer: 'Author 9',
            path: './assets/music/song9.mp3',
            image: './assets/img/image9.jpeg'
        }, 
        {
            name: 'Song 10',
            singer: 'Author 10',
            path: './assets/music/song10.mp3',
            image: './assets/img/image10.jpeg'
        },
    ],
    setConfig: function(key, value){
        this.config[key] = value;
        localStorage.setItem(PlAYER_STORAGE_KEY, JSON.stringify(this.config));
    },
    render: function(){
        // const htmls = this.songs.map(function(song,index) {
        // console.log(this) // Viết như này thì không lấy được con trỏ this nên ko thêm đc class active
        const htmls = this.songs.map((song,index) => { // Viết như này thì mới lấy được con trỏ this  
            return `
                <div class="song ${
                    index === this.currentIndex ? "active" : ""
                  }" data-index=${index}>
                    <div class="song-image"></div>
                    <div class="song-body">
                        <h3 class="title">${song.name}</h3>
                        <p class="author">${song.singer}</p>
                    </div>
                    <div class="song-option">
                    <i class="fa-solid fa-ellipsis"></i>
                    </div>
                </div>
                    `
        })
        playlist.innerHTML = htmls.join('');    
        // show background
        const pathImage = playlist.querySelectorAll('.song-image');
        this.songs.forEach(function(song, index){ 
            pathImage[index].style.backgroundImage = `url(${song.image})`;
        })
    },
    handleEvents: function(){
        const _this = this;
        // Xử lí quay ảnh image-cd
        const spinImage = imageSong.animate([{
        transform: 'rotate(360deg)'
        }],{
            duration: 10000,
            iterations: Infinity,  
        })
        spinImage.pause()

        // Xử lí khi phóng to thu nhỏ CD 
        const imageWidth = image.offsetWidth;
        document.onscroll = function(){
            // console.log(window.scrollY)
            // console.log(document.documentElement.scrollTop)
            const scroll = window.scrollY || document.documentElement.scrollTop;
            // console.log(scroll)
            let newWidth = imageWidth - scroll;
            // console.log(newWidth)
            // image.offsetWidth = newWidth; // cách này không dùng được. Offset width không thể gán lại được
            // if (newWidth < 0){
            //     newWidth = 0;
            // }
            image.style.width = newWidth > 0 ? newWidth + 'px' : 0;
            image.style.opacity = newWidth / imageWidth;
        }
        // Xử lí khi click play cách 1
        // playBtn.onclick = function(){
        //     audio.play();
        //     player.classList.add('playing');

        // }
        // pauseBtn.onclick = function(){
        //     audio.pause();
        //     player.classList.remove('playing');
        // }
        // xử lí khi click play cách 2 Tạo cờ để phân biệt 2 trạng thái
        // Để cả 2 thẻ i của nút pause và play trong cùng 1 khối 
        // Tạo thêm một biến trạng thái isPlaying.
        // Tạo một con trỏ _this = this trong hàm này để sử dụng đối tượng app
        // playBtn.onclick = function(){
        //     if (_this.isPlaying){
        //         audio.pause()
        //     }else{
        //         audio.play()
        //     }
        // }

        // audio.onplay = function(){
        //     _this.isPlaying = true
        //     player.classList.add('playing')
        // }
        // audio.onpause = function(){
        //     _this.isPlaying = false
        //     player.classList.remove('playing')
        // }
        // xử lí khi click play cách 3
        playBtn.onclick = function(){
            audio.play();
        }
        pauseBtn.onclick = function(){
            audio.pause();
        }
        audio.onplay = function(){
            audio.play()
            player.classList.add('playing')
            spinImage.play()
        }
        audio.onpause = function(){
            audio.pause()
            player.classList.remove('playing')
            spinImage.pause()
        }
        // Xử lí khi tiến độ bài hát thay đổi. Thay đổi input progress.value
        
        audio.ontimeupdate = function(){
            if (audio.duration){
                const progressPercent = audio.currentTime / audio.duration * 100
                // console.log(progressPercent)
                progress.value = progressPercent
            }
        }

        // Xử lí khi tua song
        progress.onchange = function(e){
            const seekTime = audio.duration * e.target.value / 100
            audio.currentTime = seekTime 
        }
        // Xử lí khi click vào nút ramdom cho nút ramdom sáng lên
            randomBtn.onclick = function(e){
            _this.isRandom = !_this.isRandom
            _this.setConfig('isRandom', _this.isRandom)
            randomBtn.classList.toggle('active', _this.isRandom)
            
        }
          // Xử lí bật tắt hiển thị khi click repeat bài hát
          redoBtn.onclick = function(){
            _this.isRepeat = !_this.isRepeat
            _this.setConfig('isRepeat', _this.isRepeat)
            redoBtn.classList.toggle('active', _this.isRepeat)
        }
        // Xử lí khi bấm next 
        forwardBtn.onclick = function(){
            if (_this.isRandom){
                _this.randomSong();
            }else {
                _this.nextSong();
            }
            audio.play();
            _this.render(); // có thể làm cách remove class active đi rồi thêm lại cho song sau
            // Chọn tất cả thẻ song, tìm song có chứa class .active rồi xóa đi
            // Chọn song có index bằng currentIndex rồi thêm class active vào
            _this.scrollToActiveSong();
        }
        // Xử lí khi bấm pre
        backwardBtn.onclick = function(){
            if (_this.isRandom){
                _this.randomSong();
            }else {
                _this.preSong();
            }
            audio.play();
            _this.render();
            _this.scrollToActiveSong();
        }

        // Xử lí khi kết thúc bài hát và repeat bài hát 
        audio.onended = function(){
            // if(_this.isRepeat){
            //     _this.repeatSong();
            // }else{
            //     forwardBtn.onclick()
            // }
            if(_this.isRepeat){
                audio.play()
            }else{
                forwardBtn.onclick()
            }
        }
        // Xử lí sự kiện khi click vào playlist 
        playlist.onclick = function(e){
            const songElement = e.target.closest('.song:not(.active)');
            if(songElement || e.target.closest('.song-option')){
                // Xử lí khi click vào bài hát
                if(songElement){
                    // console.log(typeof songElement.getAttribute('data-index')) 
                    // _this.currentIndex = songElement.getAttribute('data-index') // c1
                    _this.currentIndex = Number(songElement.dataset.index) // c2
                    _this.loadCurentSong()
                    _this.render()
                    audio.play()

                }
                // Xử lí khi click vào nút option
                if ( e.target.closest('.song-option')){

                }
            }
        }
    },
    loadConfig: function(){
        this.isRandom = this.config.isRandom
        this.isRepeat = this.config.isRepeat

        // Object.assign(this, this.config)
    },
    nextSong: function(){
        this.currentIndex++
        if (this.currentIndex >= this.songs.length){
            this.currentIndex = 0;
        }
        this.loadCurentSong();
    }, 
    preSong: function(){
        this.currentIndex--
        if(this.currentIndex < 0){
            this.currentIndex = this.songs.length - 1;
        }
        this.loadCurentSong();
    },
    randomSong: function(){
        let newIndex
        do{
            newIndex = Math.floor(Math.random() * this.songs.length)
        }
        while (newIndex === this.currentIndex)
        this.currentIndex = newIndex;
        this.loadCurentSong();
    },
    // repeatSong: function(){
    //     this.loadCurentSong();
    //     audio.play()
    // },
    scrollToActiveSong: function(){
        setTimeout(() => {
            $('.song.active').scrollIntoView({
                behavior: "smooth", 
                block: "center", 
                inline: "nearest",
            })
        }, 500)
    },

    defineProperty: function(){
        Object.defineProperty(this, 'currentSong', {
            get : function(){
                return this.songs[this.currentIndex];
            }
        })
    },
    loadCurentSong: function(){
        headerH2.textContent = this.currentSong.name;
        imageSong.style.backgroundImage = `url(${this.currentSong.image})`
        audio.src = this.currentSong.path
    },
    start: function(){
        this.loadConfig();
        this.defineProperty();
        this.loadCurentSong();
        this.handleEvents();

        this.render();
        randomBtn.classList.toggle('active', this.isRandom)
        redoBtn.classList.toggle('active', this.isRepeat)
    },
}

app.start();

