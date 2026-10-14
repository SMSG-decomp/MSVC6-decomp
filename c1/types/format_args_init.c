void __thiscall format_args_init(fe_message *m,char *format,int *args)

{
  m->text = format;
  m->base = 0;
  m->id = 0;
  diag_message_collect_args(m,(va_list *)args);
  return;
}

