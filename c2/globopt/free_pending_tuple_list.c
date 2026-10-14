void free_pending_tuple_list(void)

{
  c2_tuple *pcVar1;
  c2_tuple *t;
  
  pcVar1 = g_iv_scratch_list_head;
  while (t = pcVar1, t != (c2_tuple *)0x0) {
    pcVar1 = t->next;
    if (t->kind != '\x19') {
      tuple_unlink_free(t);
    }
  }
  return;
}

