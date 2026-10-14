uint __cdecl
decorate_symbol_codes_member_tail
          (byte name_code,byte bits35,byte flags1,c1_symbol *sym,void *local_static_dtor_name)

{
  c1_u8 cVar1;
  fe_name *pfVar2;
  byte bVar3;
  uint uVar4;
  
  uVar4 = ((bits35 != 8) - 1 & 0x14) + 6;
  if ((flags1 & 0x10) == 0x10) {
    name_code = 0x30;
LAB_1040f8a6:
    if (uVar4 == 0x1a) {
      bVar3 = sym->flags2 & 3;
      if (bVar3 == 2) {
        uVar4 = 0x1c;
      }
      else if (bVar3 == 3) {
        uVar4 = 0x1e;
      }
    }
    else {
      if (uVar4 == 6) {
LAB_1040f8db:
        bVar3 = sym->flags2 & 3;
        if (bVar3 == 2) {
          uVar4 = uVar4 | 8;
        }
        else if (bVar3 == 3) {
          uVar4 = uVar4 | 0x10;
        }
      }
      else if (uVar4 == 0) {
        if ((flags1 & 4) == 0) {
          uVar4 = 0x18;
          goto LAB_1040f904;
        }
        if ((sym->flags21 & 2) == 0) {
          uVar4 = ((byte)~*(byte *)((int)&sym->tail + 8) & 1) << 1;
        }
        else {
          uVar4 = 4;
        }
        goto LAB_1040f8db;
      }
      if (((uVar4 == 0x24) || (uVar4 == 0x25)) || (uVar4 == 0x26)) goto LAB_1040f913;
      if (uVar4 == 0x39) goto LAB_1040f907;
    }
LAB_1040f904:
    uVar4 = uVar4 + 0x41;
  }
  else {
    if ((flags1 & 0x20) == 0x20) {
      name_code = 0x31;
      goto LAB_1040f8a6;
    }
    if ((flags1 & 0x40) != 0) {
      name_code = 0x42;
      goto LAB_1040f8a6;
    }
    if ((bits35 == 0) || (bits35 != 0xc)) {
      pfVar2 = sym->name;
      if (pfVar2 == g_name_default_ctor_closure) {
        name_code = 0xc6;
      }
      else if (pfVar2 == g_name_local_vftable_ctor_closure) {
        name_code = 0xd4;
      }
      else if (pfVar2 == g_name_copy_ctor_closure) {
        name_code = 0xcf;
      }
      else if (pfVar2 == g_name_vector_ctor_iterator) {
        name_code = 200;
      }
      else if (pfVar2 == g_name_vector_vbase_ctor_iterator) {
        name_code = 0xca;
      }
      else if (pfVar2 == g_name_vector_dtor_iterator) {
        name_code = 0xc9;
      }
      else if (pfVar2 == g_name_eh_vector_ctor_iterator) {
        name_code = 0xcc;
      }
      else if (pfVar2 == g_name_eh_vector_vbase_ctor_iterator) {
        name_code = 0xce;
      }
      else if (pfVar2 == g_name_eh_vector_dtor_iterator) {
        name_code = 0xcd;
      }
      else if (pfVar2 == g_name_vbase_dtor) {
        name_code = 0xc4;
      }
      else if (pfVar2 == g_name_scalar_deleting_dtor) {
        name_code = 199;
      }
      else if (pfVar2 == g_name_vector_deleting_dtor) {
        name_code = 0xc5;
      }
      else {
        cVar1 = (sym->tail).fn.op_token;
        if ((cVar1 == '\0') || (cVar1 == '\x01')) {
          if (pfVar2 == local_static_dtor_name) {
            return 0x24;
          }
          if (pfVar2 == g_name_template_static_member_ctor) {
            return 0x25;
          }
          if (pfVar2 == g_name_template_static_member_dtor) {
            return 0x26;
          }
        }
        else {
          switch(cVar1) {
          case '1':
            name_code = 0x49;
            break;
          case '2':
            name_code = 0x56;
            break;
          case '3':
            name_code = 0xb4;
            break;
          case '4':
            name_code = 0x34;
            break;
          default:
            name_code = 0xc0;
            break;
          case '7':
            name_code = 0x51;
            break;
          case '8':
          case 'T':
            name_code = 0x46;
            break;
          case '9':
            name_code = 0x4b;
            break;
          case ':':
            name_code = 0xb0;
            break;
          case ';':
            name_code = 0x38;
            break;
          case '<':
            name_code = 0x37;
            break;
          case '=':
          case 'J':
            name_code = 0x44;
            break;
          case '>':
            name_code = 0x4f;
            break;
          case '?':
            name_code = 0x50;
            break;
          case '@':
          case 'U':
            name_code = 0x45;
            break;
          case 'A':
            name_code = 0x41;
            break;
          case 'B':
            name_code = 0xb3;
            break;
          case 'C':
            name_code = 0x36;
            break;
          case 'D':
            name_code = 0x4d;
            break;
          case 'E':
            name_code = 0x4e;
            break;
          case 'F':
          case 'Z':
            name_code = 0x47;
            break;
          case 'G':
            name_code = 0x5a;
            break;
          case 'H':
            name_code = 0x4c;
            break;
          case 'I':
            name_code = 0xb1;
            break;
          case 'K':
            name_code = 0x58;
            break;
          case 'L':
            name_code = 0x39;
            break;
          case 'M':
            name_code = 0x55;
            break;
          case 'N':
            name_code = 0xb5;
            break;
          case 'O':
            name_code = 0x57;
            break;
          case 'Q':
          case 0x86:
            name_code = 0x48;
            break;
          case 'R':
            name_code = 0x59;
            break;
          case 'S':
            name_code = 0x43;
            break;
          case 'W':
            name_code = 0xb2;
            break;
          case 'X':
            name_code = 0x35;
            break;
          case 'Y':
            name_code = 0x53;
            break;
          case '[':
            name_code = 0x54;
            break;
          case '\\':
            name_code = 0xb6;
            break;
          case 'v':
            name_code = 0x52;
            break;
          case 0x8c:
            name_code = ((pfVar2 != g_name_array_new) - 1U & 0xa3) + 0x32;
            break;
          case 0x8d:
            if (pfVar2 == g_name_array_delete) {
              name_code = 0xd6;
            }
            else if (pfVar2 == g_name_placement_delete_closure) {
              name_code = 0xd8;
            }
            else {
              name_code = ((pfVar2 != g_name_placement_array_delete_closure) - 1U & 0xa6) + 0x33;
            }
            break;
          case 0x93:
            name_code = 0x4a;
          }
        }
      }
      goto LAB_1040f8a6;
    }
    uVar4 = 0x39;
    name_code = 0xb9;
  }
LAB_1040f907:
  if (((sym->flags23 & 1) != 0) && ((uVar4 == 0x39 || ((sym->flags23 & 2) == 0)))) {
    uVar4 = uVar4 | 0x80;
  }
LAB_1040f913:
  if (name_code != 0) {
    uVar4 = uVar4 | (uint)name_code << 8;
  }
  return uVar4;
}

