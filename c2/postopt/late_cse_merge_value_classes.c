c2_symbol * __fastcall
late_cse_merge_value_classes(c2_symbol *classes,c2_symbol *reg,c2_operand *value)

{
  c2_symbol *pcVar1;
  c2_symbol *pcVar2;
  
  pcVar2 = classes;
  do {
    pcVar1 = pcVar2;
    if (pcVar2 == (c2_symbol *)0x0) {
LAB_10739d26:
      (reg->u30).order_prev = classes;
      reg->order_next = (c2_symbol *)0x0;
      (reg->u34).lcse_values = value;
      value->rank = 0;
      return reg;
    }
    for (; pcVar1 != (c2_symbol *)0x0; pcVar1 = pcVar1->order_next) {
      if (pcVar1 == reg) {
        if (pcVar1 != (c2_symbol *)0x0) {
          if (pcVar2 != (c2_symbol *)0x0) {
            value->rank = (uint32_t)pcVar2->u34;
            do {
              (pcVar2->u34).lcse_values = value;
              pcVar2 = pcVar2->order_next;
            } while (pcVar2 != (c2_symbol *)0x0);
            return classes;
          }
          goto LAB_10739d26;
        }
        break;
      }
    }
    pcVar2 = (pcVar2->u30).order_prev;
  } while( true );
}

