import {
    TYPE_LOG
} from './constant.js'
function logger(log, type = TYPE_LOG){
    console[type](log)
}

export default logger; // mỗi module chỉ có thể export default 1 lần, còn lại có thể export kiểu thông thường 

// export const TYPE_LOG = 'log'
// export const TYPE_WARN = 'warn'
// export const TYPE_ERROR = 'error' /. nên để các const ra file khác, những vẫn có thể đê chung như này