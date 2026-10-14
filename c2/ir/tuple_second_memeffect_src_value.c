uint32_t __fastcall tuple_second_memeffect_src_value(c2_tuple *t)

{
  c2_operand *pcVar1;
  bool bVar2;
  
  pcVar1 = t->src;
  bVar2 = false;
  do {
    if (pcVar1 == (c2_operand *)0x0) {
      ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\misc.c",0x451);
    }
    if (pcVar1->kind == '\v') {
      if (bVar2) {
        return (uint32_t)pcVar1->sym;
      }
      bVar2 = true;
    }
    pcVar1 = pcVar1->next;
  } while( true );
}

