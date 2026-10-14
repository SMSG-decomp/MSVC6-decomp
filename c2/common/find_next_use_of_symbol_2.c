c2_tuple * __fastcall find_next_use_of_symbol_2(c2_tuple *t,c2_symbol *sym)

{
  c2_tuple *pcVar1;
  
  pcVar1 = find_next_use_of_symbol((c2_node *)t,sym,(c2_operand **)0x0);
  return pcVar1;
}

