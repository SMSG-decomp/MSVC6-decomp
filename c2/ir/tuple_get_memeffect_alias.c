uint32_t __fastcall tuple_get_memeffect_alias(c2_tuple *t)

{
  c2_operand *pcVar1;
  
  pcVar1 = t->src;
  while( true ) {
    if (pcVar1 == (c2_operand *)0x0) {
      ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\misc.c",0x43d);
    }
    if (pcVar1->kind == '\v') break;
    pcVar1 = pcVar1->next;
  }
  return (uint32_t)pcVar1->sym;
}

