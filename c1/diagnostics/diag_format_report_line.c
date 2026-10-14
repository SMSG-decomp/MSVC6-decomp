void __thiscall diag_format_report_line(fe_diag_context *list,fe_message_buffer *buf,fe_message *m)

{
  ushort uVar1;
  char cVar2;
  uint uVar3;
  fe_message_buffer *pfVar4;
  size_t sVar5;
  fe_message local_48;
  
  if ((list->state == 1) || (list->state == 3)) {
    if (list->position != 0) {
      diag_message_from_format(&local_48.base,"%$P : ",list->position);
      diag_format_message(&local_48,buf);
    }
    uVar1 = m->base;
    pfVar4 = buf;
    if (uVar1 < 0xfa1) {
      if (uVar1 == 4000) {
        pfVar4 = (fe_message_buffer *)misc_string_get(0x139);
      }
      else if (uVar1 == 1000) {
        pfVar4 = (fe_message_buffer *)misc_string_get(0x13b);
      }
      else if (uVar1 == 2000) {
        pfVar4 = (fe_message_buffer *)misc_string_get(0x13a);
      }
    }
    else if (uVar1 == 6000) {
      pfVar4 = (fe_message_buffer *)misc_string_get(0x138);
    }
    diag_message_from_format(&local_48.base,"%s %c%d: ",pfVar4,0x43,(uint)m->id);
    diag_format_message(&local_48,buf);
    if ((buf->room != 0) || (cVar2 = diag_message_buffer_grow(buf), cVar2 != '\0')) {
      *buf->cur = '\0';
      buf->cur = buf->cur + 1;
    }
    if ((buf->flags & 2) != 0) {
      strncpy(buf->cur + -4,"...",4);
    }
    buf->cur = buf->cur + -1;
    sVar5 = _mbstrlen(buf->start);
    if (sVar5 < 8) {
      if ((buf->room != 0) || (cVar2 = diag_message_buffer_grow(buf), cVar2 != '\0')) {
        *buf->cur = '\0';
        buf->cur = buf->cur + 1;
      }
      if ((buf->flags & 2) != 0) {
        strncpy(buf->cur + -4,"...",4);
      }
      buf->cur = buf->cur + -1;
      sVar5 = _mbstrlen(buf->start);
    }
    else {
      sVar5 = 8;
    }
    list->indent = sVar5;
    list->state = 2;
  }
  else {
    uVar3 = list->indent;
    if ((buf->room < uVar3) && (cVar2 = diag_message_buffer_grow(buf), cVar2 == '\0')) {
      diag_message_buffer_fill(buf,' ',buf->room);
      diag_format_message(m,buf);
      return;
    }
    if (uVar3 != 0) {
      do {
        *buf->cur = ' ';
        uVar3 = uVar3 - 1;
        buf->cur = buf->cur + 1;
      } while (uVar3 != 0);
      diag_format_message(m,buf);
      return;
    }
  }
  diag_format_message(m,buf);
  return;
}

