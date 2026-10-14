c2_tuple * __fastcall tuple_new_label(c2_fe_symbol *label_sym)

{
  c2_tuple *pcVar1;
  
  pcVar1 = (c2_tuple *)node_alloc('\x1a');
  pcVar1->src = (c2_operand *)label_sym;
  (label_sym->u32).label_tuple = pcVar1;
  pcVar1->op = 0x1ae;
  pcVar1->line = 0;
  return pcVar1;
}

