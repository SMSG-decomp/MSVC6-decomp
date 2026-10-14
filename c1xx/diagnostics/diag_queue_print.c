void __fastcall diag_queue_print(c1_diag_context *ctx)

{
  c1_message *msg;
  char cVar1;
  c1xx_diag_cell *msg_cell;
  c1_message_buffer line;
  
  diag_message_buffer_new(&line);
  msg_cell = (ctx->queue).head;
  ctx->busy = '\x01';
  if (msg_cell == (c1xx_diag_cell *)0x0) {
    ctx->busy = '\0';
    return;
  }
  do {
    (ctx->queue).head = msg_cell->next;
    msg = msg_cell->msg;
    if ((ctx->queue).head == (c1xx_diag_cell *)0x0) {
      (ctx->queue).tail = (c1xx_diag_cell *)0x0;
    }
    ctx->insert_list = &ctx->queue;
    ctx->insert_after = (c1xx_diag_cell *)0x0;
    diag_format_report_line(ctx,&line,msg);
    if ((line.room != 0) || (cVar1 = diag_message_buffer_grow(&line), cVar1 != '\0')) {
      *line.cur = '\0';
      line.cur = line.cur + 1;
    }
    if ((line.flags & 2) != 0) {
      strncpy(line.cur + -4,"...",4);
    }
    line.cur = line.cur + -1;
    diag_write_line_stderr(line.start);
    diag_message_buffer_rewind(&line);
    msg_cell = (ctx->queue).head;
  } while (msg_cell != (c1xx_diag_cell *)0x0);
  ctx->busy = '\0';
  return;
}

