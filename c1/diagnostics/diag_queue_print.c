void __fastcall diag_queue_print(fe_diag_context *list)

{
  fe_message *m;
  char cVar1;
  fe_diag_cell *pfVar2;
  fe_message_buffer local_10;
  
  diag_message_buffer_new(&local_10);
  pfVar2 = (list->queue).head;
  list->busy = '\x01';
  if (pfVar2 == (fe_diag_cell *)0x0) {
    list->busy = '\0';
    return;
  }
  do {
    (list->queue).head = pfVar2->next;
    m = pfVar2->msg;
    if ((list->queue).head == (fe_diag_cell *)0x0) {
      (list->queue).tail = (fe_diag_cell *)0x0;
    }
    list->insert_list = &list->queue;
    list->insert_after = (fe_diag_cell *)0x0;
    diag_format_report_line(list,&local_10,m);
    if ((local_10.room != 0) || (cVar1 = diag_message_buffer_grow(&local_10), cVar1 != '\0')) {
      *local_10.cur = '\0';
      local_10.cur = local_10.cur + 1;
    }
    if ((local_10.flags & 2) != 0) {
      strncpy(local_10.cur + -4,"...",4);
    }
    local_10.cur = local_10.cur + -1;
    diag_write_line_stderr(local_10.start);
    diag_message_buffer_rewind(&local_10);
    pfVar2 = (list->queue).head;
  } while (pfVar2 != (fe_diag_cell *)0x0);
  list->busy = '\0';
  return;
}

