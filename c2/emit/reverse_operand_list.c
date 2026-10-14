c2_symbol * __fastcall reverse_operand_list(c2_symbol *sym)

{
  c2_fe_symbol *pcVar1;
  c2_fe_symbol *pcVar2;
  
  if (sym != (c2_symbol *)0x0) {
    pcVar2 = (c2_fe_symbol *)0x0;
    do {
      pcVar1 = ((c2_fe_symbol *)sym)->next;
      ((c2_fe_symbol *)sym)->next = pcVar2;
      pcVar2 = (c2_fe_symbol *)sym;
      sym = (c2_symbol *)pcVar1;
    } while (pcVar1 != (c2_fe_symbol *)0x0);
    return (c2_symbol *)pcVar2;
  }
  return (c2_symbol *)0x0;
}

