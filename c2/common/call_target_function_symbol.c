c2_fe_symbol * __fastcall call_target_function_symbol(c2_tuple *call)

{
  c2_operand *pcVar1;
  c2_fe_symbol *pcVar2;
  
  pcVar1 = call->src;
  if (pcVar1->kind == 4) {
    return (c2_fe_symbol *)pcVar1->sym;
  }
  if ((((1 << (pcVar1->kind & 0x1f) & 0x1eU) == 0) ||
      (pcVar2 = pcVar1->sym->storage->fe, pcVar2 == (c2_fe_symbol *)0x0)) ||
     ((pcVar2->storage & 0x1000) == 0)) {
    pcVar2 = (c2_fe_symbol *)0x0;
  }
  return pcVar2;
}

