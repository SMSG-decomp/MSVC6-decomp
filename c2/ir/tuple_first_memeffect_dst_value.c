uint32_t __fastcall tuple_first_memeffect_dst_value(c2_tuple *t)

{
  c2_operand *pcVar1;
  
  pcVar1 = t->dst;
  while( true ) {
    if (pcVar1 == (c2_operand *)0x0) {
      ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\misc.c",0x42e);
    }
    if (pcVar1->kind == '\v') break;
    pcVar1 = pcVar1->next;
  }
  return (uint32_t)pcVar1->sym;
}

