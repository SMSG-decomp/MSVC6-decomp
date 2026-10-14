void __fastcall emit_strip_scope_markers(c2_function *fn)

{
  uint32_t uVar1;
  c2_tuple *t;
  c2_const_operand *src;
  c2_operand *dst;
  c2_tuple *pcVar2;
  c2_insert_fn *insert_fn;
  
  pcVar2 = fn->cfg->first->head;
  while (t = pcVar2, t != (c2_tuple *)0x0) {
    uVar1 = t->op;
    pcVar2 = t->next;
    if (((uVar1 == 0x18b) || (uVar1 == 0x19b)) || (uVar1 == 0x19c)) {
      tuple_unlink_free(t);
    }
  }
  if ((g_seh_try_end_label != (c2_tuple *)0x0) && (g_seh_try_has_code != 0)) {
    insert_fn = tuple_insert_before;
    pcVar2 = g_seh_try_end_label;
    src = operand_new_intconst(0x1004,0,0);
    dst = operand_new_hardreg(5,0x1004);
    pcVar2 = tuple_new_exit(8,0x1004,dst,src,insert_fn,pcVar2);
    pcVar2->line = 0;
  }
  return;
}

