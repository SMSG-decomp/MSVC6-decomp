c1_symbol * __fastcall ovl_set_iter_current_symbol(c1xx_ovl_set_iter *iter)

{
  c1_sym_link *pcVar1;
  c1_symbol *pcVar2;
  
  pcVar1 = iter->current;
  pcVar2 = (c1_symbol *)&pcVar1[-1].position;
  if ((pcVar1[-1].position & 0x1f) == 0x1a) {
    pcVar2 = ((pcVar1->type).alias)->target;
  }
  return pcVar2;
}

