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

const playlist = $('.playlist');
const image = $('.image');


const app = {
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
    render: function(){
        const htmls = this.songs.map(function(song,index){
            return `
                <div class="song">
                    <div class="song-image"></div>
                    <div class="song-body">
                        <h3 class="title">${song.name}</h3>
                        <p class="author">${song.singer}</p>
                    </div>
                    <div class="song-option">
                    <i class="fa-solid fa-ellipsis+"></i>
                    </div>
                </div>
                    `
        })
        playlist.innerHTML = htmls.join('');      
        // show background
        const pathImage = playlist.querySelectorAll('.song-image');
        this.songs.map(function(song, index){ 
            pathImage[index].style.backgroundImage = `url(${song.image})`;
        })
    },
    handleEvents: function(){
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
    },
    start: function(){
        this.handleEvents();

        this.render();
    },
}

app.start();

