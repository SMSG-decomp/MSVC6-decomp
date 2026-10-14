void __thiscall format_args_init(c1_message *message,char *format,int *args)

{
  message->text = format;
  message->base = 0;
  message->id = 0;
  diag_message_collect_args(message,args);
  return;
}

