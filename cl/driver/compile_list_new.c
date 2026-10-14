node * __cdecl compile_list_new(driver_ctx *ctx)

{
  node *cur;
  node *tail;
  srcfile *f;
  node *list;
  node *head;
  
  f = ctx->files;
  list = (node *)0x0;
  tail = (node *)0x0;
  head = list;
  if (f != (srcfile *)0x0) {
    do {
      cur = tail;
      list = head;
      if ((g_file_types[f->type].kind == 0) &&
         (cur = compile_node_new(f), list = cur, head != (node *)0x0)) {
        tail->next = cur;
        list = head;
      }
      f = f->next;
      tail = cur;
      head = list;
    } while (f != (cl_srcfile *)0x0);
    if (list != cur) {
      return list;
    }
  }
  g_batch_allowed = 0;
  return list;
}

