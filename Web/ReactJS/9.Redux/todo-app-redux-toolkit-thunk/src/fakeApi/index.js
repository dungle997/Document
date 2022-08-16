import {createServer, Model} from 'miragejs' // Một cái dữ liệu từ mirape có tên là Model

export const setupServer = () => {
    let server = createServer({
        models: {
            todos: Model
        },
        routes() {
            this.get("/api/todos", (schema) => { 
               return schema.todos.all()
            });
            this.post("/api/todos", (schema, request)=> {
                const payload = JSON.parse(request.requestBody)
                return schema.todos.create(payload)
            })
            this.post('/api/updateTodo', (schema, request)=> {
                const payload = JSON.parse(request.requestBody)
                const currentTodo = schema.todos.find(payload.id)
                currentTodo.update(payload)
            })
        }
        
    })

}