void __fastcall coff_add_file_symbol(char *name)

{
  char cVar1;
  c2_coff_slot *slot;
  c2_coff_file_payload *pcVar2;
  uint32_t uVar3;
  uint uVar4;
  int naux;
  
  slot = (*g_coff_alloc_fn)(0xc);
  slot->kind = 1;
  pcVar2 = (*g_coff_alloc_fn)(8);
  uVar4 = 0xffffffff;
  slot->payload = pcVar2;
  pcVar2->name = name;
  pcVar2->value = 0;
  do {
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    cVar1 = *name;
    name = name + 1;
  } while (cVar1 != '\0');
  uVar4 = (~uVar4 - 1) / 0x12;
  naux = uVar4 + 1;
  if (g_opt_incremental != 0) {
    if (g_coff_reserved_slots_left == 0) {
      coff_alloc_symbol_slots(uVar4 + 2,0,0);
    }
    if (g_opt_incremental != 0) {
      uVar3 = coff_symtab_append(slot);
      goto LAB_10757212;
    }
  }
  uVar3 = coff_push_record(slot);
LAB_10757212:
  if (g_coff_prev_file_payload != (c2_coff_file_payload *)0x0) {
    g_coff_prev_file_payload->value = uVar3;
  }
  g_coff_prev_file_payload = pcVar2;
  slot = (*g_coff_alloc_fn)(0xc);
  slot->kind = 5;
  for (; naux != 0; naux = naux + -1) {
    if (g_opt_incremental == 0) {
      coff_push_record(slot);
    }
    else {
      coff_symtab_append(slot);
    }
  }
  return;
}

