c2_symbol * __fastcall alias_class_single_member(uint32_t cls)

{
  c2_symbol_cell *pcVar1;
  c2_symbol *pcVar2;
  
  pcVar1 = alias_class_members(cls);
  if (((pcVar1 == (c2_symbol_cell *)0x0) || (pcVar1->next != (c2_symbol_cell *)0x0)) ||
     (pcVar2 = pcVar1->sym, pcVar2->cls == '\f')) {
    pcVar2 = (c2_symbol *)0x0;
  }
  return pcVar2;
}

