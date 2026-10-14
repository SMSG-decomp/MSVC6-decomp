c2_symbol_cell * __fastcall stack_slot_aliased_symbols(c2_symbol *sym)

{
  c2_symbol *pcVar1;
  c2_stack_slot_range *pcVar2;
  int32_t iVar3;
  
  pcVar1 = sym->storage;
  if (pcVar1->cls == '\x03') {
    iVar3 = (pcVar1->u28).frame_home;
  }
  else {
    iVar3 = pcVar1->fe->offset;
  }
  pcVar2 = g_stack_slot_ranges;
  while( true ) {
    if (pcVar2 == (c2_stack_slot_range *)0x0) {
      return (c2_symbol_cell *)0x0;
    }
    if ((iVar3 < pcVar2->size + pcVar2->offset) && (pcVar2->offset < pcVar1->size + iVar3)) break;
    pcVar2 = pcVar2->next;
  }
  return pcVar2->aliased;
}

