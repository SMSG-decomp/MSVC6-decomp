uint32_t __fastcall
coff_emit_init_record(c2_init *rec,c2_fe_symbol *data_sym,c2_fe_symbol *section_sym)

{
  uint8_t uVar1;
  uint8_t uVar2;
  uint16_t uVar3;
  c2_fe_symbol *s;
  uint uVar4;
  void *pb;
  uint32_t cb;
  uint32_t uVar5;
  uint32_t uVar6;
  
  uVar5 = 0;
  coff_pad_section_to_offset(section_sym);
  switch(rec->kind) {
  case 1:
    uVar6 = (rec->u18).repeat;
    if ((int)uVar6 < 1) {
      return 0;
    }
    do {
      uVar3 = (rec->u08).data.value_kind;
      if (uVar3 == 6) {
        pb = (void *)(rec->u08).header.offset;
        cb = (uint32_t)(rec->u08).data.size;
LAB_107505e2:
        coff_write_bytes(pb,cb);
      }
      else {
        uVar4 = (uint)(rec->u08).data.size;
        switch(uVar4) {
        case 1:
          coff_write_fill(*(uint8_t *)((int)&rec->u08 + 4),uVar6);
          if (1 < (int)uVar6) {
            uVar5 = uVar5 + (uVar6 - 1) * uVar4;
          }
          uVar6 = 0;
          break;
        case 2:
          coff_write_word_arg(*(uint16_t *)((int)&rec->u08 + 4));
          break;
        default:
          ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\coff.c",0x50e);
        case 4:
          if (uVar3 == 5) {
            cb = 4;
            goto LAB_1075064a;
          }
          coff_write_dword_arg((rec->u08).header.offset);
          break;
        case 8:
          if (uVar3 == 5) {
            cb = 8;
            goto LAB_1075064a;
          }
          coff_write_dword_arg((rec->u08).header.offset);
          coff_write_dword_arg((rec->u08).header.sym_id);
          break;
        case 10:
          cb = 10;
LAB_1075064a:
          pb = (void *)((int)&rec->u08 + 4);
          goto LAB_107505e2;
        }
      }
      uVar5 = uVar5 + (rec->u08).data.size;
      uVar6 = uVar6 - 1;
      if ((int)uVar6 < 1) {
        return uVar5;
      }
    } while( true );
  case 2:
    uVar1 = (rec->u08).address.size;
    uVar5 = (uint32_t)(char)uVar1;
    s = fe_symbol_lookup_id((rec->u08).address.target_id);
    if (((s->cls == '\x04') || (s->cls == '\x01')) && ((s->storage & 0x1000) != 0)) {
      s = (c2_fe_symbol *)fe_symbol_resolve_redirect((int)s);
    }
    uVar2 = s->cls;
    if (uVar2 == '\x01') {
      uVar6 = (rec->u08).header.offset;
    }
    else {
      if (uVar2 == '\x03') {
        if ((*(byte *)&s->u3e & 1) == 0) {
          ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\coff.c",0x547);
        }
      }
      else if (uVar2 != '\x04') {
        ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\coff.c",0x55b);
      }
      uVar6 = 0;
    }
    if ('\x03' < (char)uVar1) {
      coff_add_reloc_dir32(0,s);
      coff_write_dword_arg(uVar6);
      if ((char)uVar1 < '\x05') {
        return uVar5;
      }
      coff_write_fill('\0',uVar5 - 4);
      return uVar5;
    }
    break;
  default:
    ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\coff.c",0x5c1);
  case 4:
    uVar4 = coff_section_current_offset(g_coff_code_section_id);
    uVar4 = uVar4 % (uint)(int)(char)(rec->u08).align;
    if (uVar4 == 0) {
      return 0;
    }
    coff_write_fill('\0',1);
    return uVar4;
  case 8:
    uVar5 = (rec->u08).address.target_id;
    break;
  case 0x10:
    uVar4 = (uint)(rec->u08).data.size;
    switch(uVar4) {
    case 1:
      coff_write_fill(*(uint8_t *)((int)&rec->u08 + 4),1);
      return uVar4;
    case 2:
      coff_write_word_arg(*(uint16_t *)((int)&rec->u08 + 4));
      return uVar4;
    default:
      ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\coff.c",0x530);
    case 4:
      coff_write_dword_arg((rec->u08).header.offset);
      return uVar4;
    case 8:
      coff_write_dword_arg((rec->u08).header.offset);
      coff_write_dword_arg((rec->u08).header.sym_id);
      return uVar4;
    }
  }
  coff_write_fill('\0',uVar5);
  return uVar5;
}

