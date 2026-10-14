void __cdecl
decl_apply_declarator_modifiers
          (ushort convention,c1_type *base,c1_type *layer,c1_type_declarator *declarator)

{
  ushort uVar1;
  c1_type *pcVar2;
  c1_type *pcVar3;
  uint uVar4;
  
  uVar4 = (uint)convention;
code_r0x10604ece:
  layer->flags = layer->flags | (ushort)uVar4;
  do {
    while( true ) {
      pcVar3 = layer;
      layer = pcVar3->base;
      if (layer == base) {
        decl_warn_modifiers_on_data(declarator);
        pcVar3 = declarator->first;
        pcVar2 = declarator->last->base;
        if (pcVar3 != pcVar2) {
          pcVar2 = type_rebuild_chain(pcVar3->base,pcVar2);
          pcVar3->base = pcVar2;
          pcVar3 = type_intern(pcVar3);
        }
        declarator->type = pcVar3;
        if (declarator->type == (c1_type *)0x0) {
          declarator->flags30 = declarator->flags30 | 1;
          declarator->type = g_type_int;
        }
        return;
      }
      uVar4 = (byte)layer->flags & 7;
      uVar1 = (ushort)uVar4;
      if (uVar1 != 0) break;
      if ((layer->code & 0x83) == 0x81) {
        if (layer == declarator->first) {
          uVar1 = (ushort)declarator->modifiers & 7;
          uVar4 = (uint)uVar1;
          if (uVar1 == 0) {
            declarator->flags30 = declarator->flags30 & 0xfd;
            uVar4 = decl_default_calling_convention(layer);
          }
          else {
            *(ushort *)&declarator->modifiers = (ushort)declarator->modifiers & 0xfff8;
          }
        }
        else {
          pcVar2 = type_skip_arrays(pcVar3);
          if ((pcVar2->flags & 7) == 0) {
            uVar4 = decl_default_calling_convention(layer);
            goto LAB_10604f4f;
          }
          if ((pcVar3->code & 0x8f) == 0x83) {
            pcVar3 = type_skip_arrays(pcVar3->base);
            uVar4 = (byte)pcVar3->flags & 7;
          }
          else {
            uVar4 = (byte)pcVar3->flags & 7;
          }
        }
        goto code_r0x10604ece;
      }
    }
    layer->flags = layer->flags & 0xfff8;
    switch((byte)layer->code & 0x8f) {
    case 0x81:
    case 0x85:
      goto switchD_10604ea3_caseD_81;
    case 0x82:
      diag_error(0xa5,0x78);
      declarator->flags30 = declarator->flags30 | 1;
      break;
    case 0x86:
      if (layer->base != base) {
        uVar1 = decl_check_varargs_calling_convention(layer->base,uVar1);
        decl_apply_declarator_modifiers(uVar1,base,layer,declarator);
        return;
      }
      goto code_r0x10604ece;
    }
  } while( true );
switchD_10604ea3_caseD_81:
  uVar1 = decl_check_varargs_calling_convention(layer,uVar1);
  uVar4 = (uint)uVar1;
  if (layer != declarator->first) {
LAB_10604f4f:
    pcVar3->flags = pcVar3->flags | (ushort)uVar4;
  }
  goto code_r0x10604ece;
}

