void __cdecl lookup_member_pointer_class(c1_symbol **out_class,c1_overload_set *qualifier)

{
  c1_symbol *pcVar1;
  byte bVar2;
  
  pcVar1 = qualifier->list->head->sym;
  if (((pcVar1->kind & 0x1f) == 10) && ((pcVar1->storage & 7) == 7)) {
    if ((pcVar1->type->code & 0x200) == 0) {
      diag_error(0x28d,0x53,pcVar1);
      *out_class = (c1_symbol *)0x0;
      return;
    }
    pcVar1 = (pcVar1->type->extra).cls;
  }
  if ((pcVar1->kind & 0x1f) == 0xf) {
    pcVar1 = g_scope_vector->entries[(short)pcVar1->key_ref];
  }
  bVar2 = pcVar1->kind & 0x1f;
  if ((bVar2 != 4) && (bVar2 != 0x16)) {
    diag_error(0x28d,0x53,pcVar1);
    *out_class = (c1_symbol *)0x0;
    return;
  }
  *out_class = pcVar1;
  return;
}

