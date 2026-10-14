char * __cdecl format_buffer_text_trimmed(int buf)

{
  c1_text_buffer *pcVar1;
  uint uVar2;
  
  pcVar1 = format_buffer_find(buf);
  if (pcVar1 == (c1_text_buffer *)0x0) {
    return (char *)0x0;
  }
  uVar2 = pcVar1->end - 1;
  if (pcVar1->front < uVar2) {
    do {
      if (pcVar1->data[uVar2] != ' ') break;
      pcVar1->data[uVar2] = '\0';
      uVar2 = uVar2 - 1;
      pcVar1->end = pcVar1->end - 1;
    } while (pcVar1->front < uVar2);
  }
  return pcVar1->data + pcVar1->front + 1;
}

