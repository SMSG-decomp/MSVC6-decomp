void __fastcall decl_finish_declarator(c1_type_declarator *declarator)

{
  c1_type *layer;
  ushort uVar1;
  c1_type *pcVar2;
  c1_type *pcVar3;
  int iVar4;
  c1_type *pcVar5;
  
  if (declarator->first == (c1_type *)0x0) {
    decl_warn_modifiers_on_data(declarator);
    declarator->flags30 = declarator->flags30 | 4;
    declarator->type = declarator->base;
  }
  else {
    decl_check_declarator_type(declarator);
    if ((declarator->flags14 & 1) != 0) {
      pcVar3 = declarator->last->base;
      if ((declarator->flags30 & 8) != 0) {
        declarator->flags30 = declarator->flags30 | 2;
      }
      pcVar2 = (c1_type *)0x0;
      for (layer = declarator->first; layer != pcVar3; layer = layer->base) {
        uVar1 = layer->flags & 7;
        if (uVar1 == 0) {
          if ((layer->code & 0x83) == 0x81) {
            if (layer == declarator->first) {
              uVar1 = (ushort)declarator->modifiers & 7;
              if (uVar1 == 0) {
                declarator->flags30 = declarator->flags30 & 0xfd;
                iVar4 = decl_default_calling_convention(layer);
                uVar1 = (ushort)iVar4;
              }
              else {
                *(ushort *)&declarator->modifiers = (ushort)declarator->modifiers & 0xfff8;
              }
            }
            else {
              pcVar5 = type_skip_arrays(pcVar2);
              if ((pcVar5->flags & 7) == 0) {
                iVar4 = decl_default_calling_convention(layer);
                uVar1 = (ushort)iVar4;
                goto LAB_10604f4f;
              }
              if ((pcVar2->code & 0x8f) == 0x83) {
                pcVar2 = type_skip_arrays(pcVar2->base);
                uVar1 = (byte)pcVar2->flags & 7;
              }
              else {
                uVar1 = (byte)pcVar2->flags & 7;
              }
            }
            goto code_r0x10604ece;
          }
          goto switchD_10604ea3_caseD_83;
        }
        layer->flags = layer->flags & 0xfff8;
        switch((byte)layer->code & 0x8f) {
        case 0x81:
        case 0x85:
          uVar1 = decl_check_varargs_calling_convention(layer,uVar1);
          if (layer != declarator->first) {
LAB_10604f4f:
            pcVar2->flags = pcVar2->flags | uVar1;
          }
          goto code_r0x10604ece;
        case 0x82:
          diag_error(0xa5,0x78);
          declarator->flags30 = declarator->flags30 | 1;
          break;
        case 0x86:
          if (layer->base != pcVar3) {
            uVar1 = decl_check_varargs_calling_convention(layer->base,uVar1);
            decl_apply_declarator_modifiers(uVar1,pcVar3,layer,declarator);
            return;
          }
code_r0x10604ece:
          layer->flags = layer->flags | uVar1;
        }
switchD_10604ea3_caseD_83:
        pcVar2 = layer;
      }
    }
    decl_warn_modifiers_on_data(declarator);
    pcVar3 = declarator->first;
    pcVar2 = declarator->last->base;
    if (pcVar3 != pcVar2) {
      pcVar2 = type_rebuild_chain(pcVar3->base,pcVar2);
      pcVar3->base = pcVar2;
      pcVar3 = type_intern(pcVar3);
    }
    declarator->type = pcVar3;
  }
  if (declarator->type == (c1_type *)0x0) {
    declarator->flags30 = declarator->flags30 | 1;
    declarator->type = g_type_int;
  }
  return;
}

