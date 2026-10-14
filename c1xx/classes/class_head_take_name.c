byte __thiscall class_head_take_name(void *head,c1_u8 *token)

{
  if ((*(int *)head == 0) && (*(int *)((int)head + 4) == 0)) {
    *(c1_u8 **)((int)head + 8) = token;
    if (*token == '\x06') {
      *(undefined4 *)head = *(undefined4 *)(token + 8);
      return 1;
    }
    *(undefined4 *)head = **(undefined4 **)(token + 8);
    return 1;
  }
  (*g_token_source->stream->vtbl->unget)(g_token_source->stream,(char *)token);
  *(undefined1 *)((int)head + 0x30) = 0;
  return 0;
}

