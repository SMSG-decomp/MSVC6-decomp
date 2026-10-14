c2_tuple * __fastcall find_next_use_of_temp(c2_symbol *reg,c2_tuple *t,c2_operand **op)

{
  c2_operand *pcVar1;
  
  do {
    if (t == (c2_tuple *)0x0) {
      ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\regasg.c",0x286);
    }
    if ((t->flags & 1) != 0) {
      for (pcVar1 = t->src; pcVar1 != (c2_operand *)0x0; pcVar1 = pcVar1->next) {
        if ((pcVar1->kind == '\x01') && ((pcVar1->u18).reg == reg)) {
          *op = pcVar1;
          return t;
        }
      }
    }
    t = t->next;
  } while( true );
}

