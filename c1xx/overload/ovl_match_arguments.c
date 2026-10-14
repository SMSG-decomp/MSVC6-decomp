char __thiscall ovl_match_arguments(void *ctx,c1_node *object)

{
  char cVar1;
  byte bVar2;
  c1_u8 cVar3;
  c1_ovl_candidate *cand;
  c1_node *pcVar4;
  c1_symbol *pcVar5;
  uint uVar6;
  c1_type *pcVar7;
  c1_type *pcVar8;
  int iVar9;
  byte *conv;
  int local_18;
  c1_type local_10;
  
  if (object != (c1_node *)0x0) {
    object = expr_build_builtin_unary(0x3d,object);
  }
  cand = *(c1_ovl_candidate **)((int)ctx + 0x18);
  do {
    if (cand == (c1_ovl_candidate *)0x0) {
switchD_10413242_caseD_1:
      return '\x01';
    }
    conv = &cand->conversions->op;
    local_18 = 1;
    if (object == (c1_node *)0x0) {
      if ((cand->flags & 2) != 0) goto LAB_10413109;
LAB_10413113:
      iVar9 = *(int *)((int)ctx + 0x40);
      cand->param_cursor = cand->params;
      if (cand->argument < *(uint *)((int)ctx + 0x10)) {
        do {
          iVar9 = *(int *)(iVar9 + 8);
          if (*(int *)(iVar9 + 0x10) == 0) {
            return '\0';
          }
          ovl_set_failure_reason(ctx,3,local_18);
          cand->param_type = *cand->param_cursor;
          if ((c1_conversion *)conv == (c1_conversion *)0x0) {
            conv = (byte *)0x0;
          }
          else {
            pcVar7 = *cand->param_cursor;
            bVar2 = *(byte *)((int)ctx + 0x34);
            pcVar4 = *(c1_node **)(iVar9 + 0x10);
            ((c1_conversion *)conv)->op = '`';
            ((c1_conversion *)conv)->mode = '\x03';
            ((c1_conversion *)conv)->flags = bVar2 & 0x60 | 4;
            ((c1_conversion *)conv)->expr = pcVar4;
            if (pcVar4 == (c1_node *)0x0) {
              local_10.base = (c1_type *)0x0;
              local_10.debug_index = 0;
              local_10.flags = 0;
              local_10.extra.cls = (c1_symbol *)0x0;
              local_10.code = 0x80f;
              pcVar8 = type_intern(&local_10);
            }
            else {
              pcVar8 = pcVar4->type;
            }
            ((c1_conversion *)conv)->source = pcVar8;
            ((c1_conversion *)conv)->target = pcVar7;
            conv_compute_conversion((c1_conversion *)conv);
          }
          uVar6 = ovl_check_argument_conversion
                            (ctx,(c1_conversion *)conv,cand,cand->argument,
                             *(c1_node **)(iVar9 + 0x10),2);
          switch(uVar6) {
          case 0:
            goto switchD_10413242_caseD_0;
          case 1:
            goto switchD_10413242_caseD_1;
          case 2:
            goto switchD_10413242_caseD_2;
          case 3:
            break;
          default:
            local_18 = local_18 + 1;
            cand->param_cursor = cand->param_cursor + 1;
            conv = (byte *)((int)conv + 0x50);
            cand->argument = cand->argument + 1;
          }
        } while (cand->argument < *(uint *)((int)ctx + 0x10));
      }
switchD_10413242_caseD_2:
    }
    else {
      ovl_set_failure_reason(ctx,2,0);
      if (cand->object_type == (c1_type *)0x0) {
LAB_10413109:
        conv = (byte *)((int)conv + 0x50);
        cand->argument = cand->argument + 1;
        goto LAB_10413113;
      }
      pcVar7 = object->type;
      cVar1 = (char)pcVar7->code;
      while (cVar1 < '\0') {
        pcVar7 = pcVar7->base;
        cVar1 = (char)pcVar7->code;
      }
      if ((((pcVar7->flags & 0x3e0) != 0) && (pcVar5 = cand->function, pcVar5 != (c1_symbol *)0x0))
         && ((((pcVar5->flags1 & 0x10) == 0x10 || ((pcVar5->flags1 & 0x20) == 0x20)) ||
             ((cVar3 = (pcVar5->tail).fn.special_kind, '\x04' < (char)cVar3 && ((char)cVar3 < '\v'))
             )))) {
        pcVar7 = type_without_flags(object->type,0x3e0);
        object->type = pcVar7;
      }
      if ((c1_conversion *)conv == (c1_conversion *)0x0) {
        conv = (byte *)0x0;
      }
      else {
        pcVar7 = cand->object_type;
        ((c1_conversion *)conv)->op = '`';
        ((c1_conversion *)conv)->mode = '\x03';
        ((c1_conversion *)conv)->flags = 0xa0;
        ((c1_conversion *)conv)->expr = object;
        ((c1_conversion *)conv)->source = object->type;
        ((c1_conversion *)conv)->target = pcVar7;
        conv_compute_conversion((c1_conversion *)conv);
      }
      uVar6 = ovl_check_argument_conversion(ctx,(c1_conversion *)conv,cand,cand->argument,object,3);
      if (uVar6 == 0) {
switchD_10413242_caseD_0:
        return '\0';
      }
      if (uVar6 == 1) {
        return '\x01';
      }
      if (uVar6 != 3) goto LAB_10413109;
    }
    cand = cand->next;
  } while( true );
}

