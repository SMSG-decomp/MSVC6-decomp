c2_operand * __fastcall ra_find_rewritable_reg_source(c2_tuple *t,c2_live_range *picked)

{
  uint8_t uVar1;
  uint uVar2;
  c2_operand *pcVar3;
  c2_operand *pcVar4;
  c2_operand *pcVar5;
  c2_operand *pcVar6;
  c2_live_range *src_range;
  
  uVar2 = t->op;
  if ((((uVar2 != 0) && (uVar2 < 0x144)) && (t->kind != '\x0e')) &&
     ((pcVar3 = t->dst, pcVar3 == (c2_operand *)0x0 ||
      (((pcVar3->kind == '\x01' && (t->src != (c2_operand *)0x0)) &&
       (t->src->next != (c2_operand *)0x0)))))) {
    pcVar4 = t->src;
    for (pcVar5 = pcVar4; pcVar6 = pcVar4, pcVar5 != (c2_operand *)0x0; pcVar5 = pcVar5->next) {
      if (pcVar5->kind == 2) {
        return (c2_operand *)0x0;
      }
      if ((1 << (pcVar5->kind & 0x1f) & 0x60U) != 0) {
        return (c2_operand *)0x0;
      }
    }
    for (; pcVar6 != (c2_operand *)0x0; pcVar6 = pcVar6->next) {
      if ((((pcVar6->kind == '\x01') && (src_range = (pcVar6->u18).range, src_range->kind == '\x02')
           ) && (((src_range != picked &&
                  ((((src_range->colour == (c2_register_descriptor *)0x0 &&
                     (uVar1 = pcVar6->sym->cls, uVar1 != '\r')) && (uVar1 != '\x03')) &&
                   ((pcVar3 == (c2_operand *)0x0 || ((pcVar3->u18).reg != (c2_symbol *)src_range))))
                  )) && (uVar2 != 0xca)))) && (uVar2 != 0xcb)) {
        if (uVar2 != 0x33) {
          return pcVar6;
        }
        if (pcVar6 == pcVar4) {
          return pcVar6;
        }
      }
    }
  }
  return (c2_operand *)0x0;
}

