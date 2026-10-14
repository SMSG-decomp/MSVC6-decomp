void __thiscall diag_format_report_line(c1_diag_context *ctx,c1_message_buffer *out,c1_message *msg)

{
  ushort uVar1;
  char cVar2;
  uint uVar3;
  c1_message_buffer *pcVar4;
  size_t sVar5;
  c1_message local_48;
  
  if ((ctx->state == 1) || (ctx->state == 3)) {
    if (ctx->position != 0) {
      diag_message_from_format(&local_48.base,"%$P : ",ctx->position);
      diag_format_message(&local_48,out);
    }
    uVar1 = msg->base;
    pcVar4 = out;
    if (uVar1 < 0xfa1) {
      if (uVar1 == 4000) {
        pcVar4 = (c1_message_buffer *)misc_string_get(0x139);
      }
      else if (uVar1 == 1000) {
        pcVar4 = (c1_message_buffer *)misc_string_get(0x13b);
      }
      else if (uVar1 == 2000) {
        pcVar4 = (c1_message_buffer *)misc_string_get(0x13a);
      }
    }
    else if (uVar1 == 6000) {
      pcVar4 = (c1_message_buffer *)misc_string_get(0x138);
    }
    diag_message_from_format(&local_48.base,"%s %c%d: ",pcVar4,0x43,(uint)msg->id);
    diag_format_message(&local_48,out);
    if ((out->room != 0) || (cVar2 = diag_message_buffer_grow(out), cVar2 != '\0')) {
      *out->cur = '\0';
      out->cur = out->cur + 1;
    }
    if ((out->flags & 2) != 0) {
      strncpy(out->cur + -4,"...",4);
    }
    out->cur = out->cur + -1;
    sVar5 = _mbstrlen(out->start);
    if (sVar5 < 8) {
      if ((out->room != 0) || (cVar2 = diag_message_buffer_grow(out), cVar2 != '\0')) {
        *out->cur = '\0';
        out->cur = out->cur + 1;
      }
      if ((out->flags & 2) != 0) {
        strncpy(out->cur + -4,"...",4);
      }
      out->cur = out->cur + -1;
      sVar5 = _mbstrlen(out->start);
    }
    else {
      sVar5 = 8;
    }
    ctx->indent = sVar5;
    ctx->state = 2;
  }
  else {
    uVar3 = ctx->indent;
    if ((out->room < uVar3) && (cVar2 = diag_message_buffer_grow(out), cVar2 == '\0')) {
      diag_message_buffer_fill((int *)out,' ',out->room);
      diag_format_message(msg,out);
      return;
    }
    if (uVar3 != 0) {
      do {
        *out->cur = ' ';
        uVar3 = uVar3 - 1;
        out->cur = out->cur + 1;
      } while (uVar3 != 0);
      diag_format_message(msg,out);
      return;
    }
  }
  diag_format_message(msg,out);
  return;
}

