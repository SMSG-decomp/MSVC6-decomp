int __fastcall range_touches_reg(c2_tuple **from,c2_tuple *end,c2_symbol *reg)

{
  c2_tuple *t;
  c2_operand *pcVar1;
  
  t = *from;
  while ((t != end &&
         (((t->flags & 1) == 0 ||
          ((pcVar1 = find_dst_clobbering_reg(t,reg), pcVar1 == (c2_operand *)0x0 &&
           (pcVar1 = find_src_overlapping_reg(t,reg), pcVar1 == (c2_operand *)0x0))))))) {
    t = t->next;
  }
  return (uint)(t != end);
}

