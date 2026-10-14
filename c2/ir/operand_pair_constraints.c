void __fastcall
operand_pair_constraints(c2_tuple *t,c2_operand *d,c2_operand *s,c2_operand *s2,uint32_t *out)

{
  uint8_t uVar1;
  int iVar2;
  uint uVar3;
  
  if (d == (c2_operand *)0x0) {
    return;
  }
  if (s == (c2_operand *)0x0) {
    return;
  }
  uVar3 = g_x86_op_flags[t->op];
  if ((uVar3 & 0x40) == 0) {
    if (((1 << (s->kind & 0x1f) & 0x18U) == 0) || (s->op != 0x14a)) goto LAB_10712f1c;
    uVar3 = *out | 2;
  }
  else {
    if (((*out & 2) != 0) && (d->kind != '\x01')) {
      *out = *out | 1;
    }
    if ((((uVar3 & 0x1000) == 0) || (iVar2 = operand_compare(d,s2), iVar2 != 0)) ||
       (s->kind != '\x01')) {
      iVar2 = operand_compare(d,s);
      if (iVar2 == 0) {
        if (((s->kind == '\x01') || (s2 == (c2_operand *)0x0)) ||
           ((s2->kind != '\x02' && (s2->kind != '\x06')))) {
          if ((1 << (d->kind & 0x1f) & 0x60U) == 0) goto LAB_10712f1c;
          if (s2 == (c2_operand *)0x0) {
            return;
          }
          if ((1 << (s2->kind & 0x1f) & 0x60U) == 0) goto LAB_10712f1c;
          uVar3 = *out | 3;
        }
        else {
          if ((*out & 2) != 0) goto LAB_10712f1c;
          uVar3 = *out | 4;
        }
      }
      else {
        uVar1 = d->kind;
        if (uVar1 == '\x01') {
          if (((d->sym->cls == '\x03') && (d->sym->def != (c2_tuple *)0x0)) &&
             (((((d->u18).reg)->cls == '\x03' &&
               (((((d->u18).reg)->def != (c2_tuple *)0x0 && (s->kind == '\x01')) &&
                (s->sym->cls == '\x03')))) &&
              (((s->sym->def != (c2_tuple *)0x0 && (((s->u18).reg)->cls == '\x03')) &&
               (((s->u18).reg)->def != (c2_tuple *)0x0)))))) {
            uVar3 = *out | 8;
            goto LAB_10712fc0;
          }
          if (((s->kind == '\x01') && ((d->u18).reg == (s->u18).reg)) &&
             (iVar2 = is_register_candidate_home((d->u18).reg), iVar2 == 0)) goto LAB_10712f1c;
        }
        uVar3 = *out;
        *out = uVar3 | 2;
        if (uVar1 == '\x01') goto LAB_10712f1c;
        uVar3 = uVar3 | 3;
      }
    }
    else {
      uVar3 = *out | 0x10;
    }
  }
LAB_10712fc0:
  *out = uVar3;
LAB_10712f1c:
  if (((s2 != (c2_operand *)0x0) && ((1 << (s2->kind & 0x1f) & 0x18U) != 0)) && (s2->op == 0x14a)) {
    *out = *out | 4;
  }
  return;
}

