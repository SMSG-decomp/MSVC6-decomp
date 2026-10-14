uint32_t __fastcall iv_operand_has_unpaired_def(c2_operand *op)

{
  c2_list_cell *pcVar1;
  
  pcVar1 = op->sym->defs;
  while( true ) {
    if (pcVar1 == (c2_list_cell *)0x0) {
      return 0;
    }
    if (((pcVar1->u04).tuple)->flags13 != '\x04') break;
    pcVar1 = pcVar1->next;
  }
  return 1;
}

