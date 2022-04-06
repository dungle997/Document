// Cách không tối ưu
// import logger from './logger.js';
// export default logger;

import logger from './logger.js'

// Ngắn gọn hơn
// export { default } from './logger.js' 

export { default as logger2} from './logger.js' // có thể đổi tên hàm được export thông qua cú pháp này 


// Thực tế có 1 cái endpoint như index.js để có thể export ra ngòai được 


// file index được dùng để trung gian cho file logger.js. file main sẽ link đến file index để lấy hàm thay vì lấy trực tiếp từ file logger.js