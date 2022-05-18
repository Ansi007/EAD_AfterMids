public class MySecondMiddleware{
    RequestDelegate next;

    public MySecondMiddleware(RequestDelegate nextD){
        this.next = nextD;
    }

    public async Task Invoke(HttpContext context){
        if(context.Request.Path.Equals("/short")){
            await context.Response.WriteAsync("HELLO I AM SHORT\n");
        }
        else {
            await next(context);
        }
    }
}