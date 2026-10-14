c1_node * __cdecl init_template_static_member(c1_node *left,c1_node *item,int value,c1_node *item2)

{
  char cVar1;
  c1_type *pcVar2;
  byte bVar3;
  c1_node *pcVar4;
  c1_symbol *sym;
  
  bVar3 = g_init_symbol->storage & 7;
  if ((bVar3 == 0) || (3 < bVar3)) {
    pcVar2 = g_init_symbol->type;
    cVar1 = (char)pcVar2->code;
    while (cVar1 < '\0') {
      pcVar2 = pcVar2->base;
      cVar1 = (char)pcVar2->code;
    }
    sym = (pcVar2->extra).cls;
    if (((sym->flags1 & 0x20) == 0x20) && ((((sym->detail).cls)->implicit_state41 & 0x10) == 0)) {
      pcVar4 = expr_build_vector_dtor_call(item,value,item2,sym->type);
      pcVar4 = expr_build_eh_state_update(left,pcVar4,sym);
      return pcVar4;
    }
  }
  return left;
}

