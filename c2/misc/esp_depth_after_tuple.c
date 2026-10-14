int __fastcall esp_depth_after_tuple(c2_tuple *t,int esp_depth)

{
  c2_operand *operands;
  c2_operand *operands_00;
  uint uVar1;
  c2_switch_case *pcVar2;
  c2_tuple *pcVar3;
  
  if ((t->flags & 1) == 0) {
    return esp_depth;
  }
  operands = t->dst;
  set_frame_operand_esp_adjust(operands,esp_depth);
  operands_00 = t->src;
  set_frame_operand_esp_adjust(operands_00,esp_depth);
  uVar1 = t->op;
  if (0x2e < uVar1) {
    if (0xba < uVar1) {
      if ((uVar1 == 0x113) || (uVar1 == 0x11b)) {
switchD_1073ee29_caseD_f:
        if (operands_00->kind != '\x04') {
          return esp_depth;
        }
        pcVar3 = *(c2_tuple **)&(operands_00->sym->u30).globopt.marks;
        if (pcVar3 == (c2_tuple *)0x0) {
          return esp_depth;
        }
        if (pcVar3->flags12 != '\0') {
          if (*(int *)((int)&pcVar3->src[1].op + 2) == esp_depth) {
            return esp_depth;
          }
          ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\x86\\MDmisc.c",0x8c6);
        }
      }
      else {
        if (uVar1 != 0x18d) {
          return esp_depth;
        }
        for (pcVar2 = (t->u24).cases; pcVar2 != (c2_switch_case *)0x0; pcVar2 = pcVar2->next) {
          pcVar3 = pcVar2->label;
          if (pcVar3 == (c2_tuple *)0x0) {
            ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\x86\\MDmisc.c",0x8d0);
          }
          if (pcVar3->flags12 == '\0') {
            *(int *)((int)&pcVar3->src[1].op + 2) = esp_depth;
            propagate_esp_depth(pcVar3,esp_depth);
          }
          else if (*(int *)((int)&pcVar3->src[1].op + 2) != esp_depth) {
            ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\x86\\MDmisc.c",0x8d2);
          }
        }
        pcVar3 = (t->u20).default_label;
        if (pcVar3->flags12 != '\0') {
          if (*(int *)((int)&pcVar3->src[1].op + 2) == esp_depth) {
            return esp_depth;
          }
          ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\x86\\MDmisc.c",0x8da);
        }
      }
      *(int *)((int)&pcVar3->src[1].op + 2) = esp_depth;
      propagate_esp_depth(pcVar3,esp_depth);
      return esp_depth;
    }
    if (uVar1 == 0xba) goto switchD_1073ee29_caseD_d;
    if (uVar1 == 0x32) {
      if (operands->kind != '\x01') {
        return esp_depth;
      }
      if (((operands->u18).reg)->id != 5) {
        return esp_depth;
      }
      return esp_depth - (operands_00->next->u18).lo;
    }
    if (uVar1 == 0xa7) {
      return 0;
    }
    if (uVar1 != 0xb9) {
      return esp_depth;
    }
switchD_1073ee29_caseD_c:
    return esp_depth + 4;
  }
  if (uVar1 == 0x2e) {
    if (operands->kind != '\x01') {
      return esp_depth;
    }
    if (((operands->u18).reg)->id != 5) {
      return esp_depth;
    }
    if (operands_00->next->kind != '\a') {
      return esp_depth;
    }
    if ((operands_00->next->u18).reg != (c2_symbol *)0xfffffff8) {
      return esp_depth;
    }
    return 0;
  }
  switch(uVar1) {
  case 1:
    if (operands->kind != '\x01') {
      return esp_depth;
    }
    if (((operands->u18).reg)->id != 5) {
      return esp_depth;
    }
    if (operands_00->kind != '\x01') {
      return esp_depth;
    }
    if (((operands_00->u18).reg)->id != 6) {
      return esp_depth;
    }
    return -4;
  default:
    return esp_depth;
  case 0xc:
    goto switchD_1073ee29_caseD_c;
  case 0xd:
switchD_1073ee29_caseD_d:
    return esp_depth + -4;
  case 0xe:
    if (t == g_chkstk_call_tuple) {
      if (g_eh_record_pushed != 0) {
        return esp_depth + (g_frame_eh_record->size - g_cur_func_sym->frame_size);
      }
      return esp_depth - g_cur_func_sym->frame_size;
    }
    if (t != g_eh_prolog_call_tuple) {
      return (int)&((t->u20).cond_cells)->next + esp_depth;
    }
    return esp_depth + -0xc;
  case 0xf:
  case 0x10:
  case 0x16:
    goto switchD_1073ee29_caseD_f;
  case 0x2d:
    if (operands->kind != '\x01') {
      return esp_depth;
    }
    if (((operands->u18).reg)->id != 5) {
      return esp_depth;
    }
    return (int)&((operands_00->next->u18).reg)->fe + esp_depth;
  }
}

