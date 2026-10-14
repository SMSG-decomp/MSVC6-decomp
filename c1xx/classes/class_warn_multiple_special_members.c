void __cdecl
class_warn_multiple_special_members(c1_symbol *cls,c1_u8 *states,int *ctor_count,int *assign_count)

{
  byte bVar1;
  char cVar2;
  c1_symbol *pcVar3;
  c1_symbol *pcVar4;
  bool bVar5;
  c1_member_iter local_28;
  c1xx_ovl_set_iter local_10;
  
  class_member_iter_init(&local_28,&cls->name,2);
  ovl_set_iter_init(&local_10,(void *)0x0);
  *assign_count = 0;
  *ctor_count = 0;
  while( true ) {
    while (cVar2 = (*(local_10.vtbl)->ovl_set_iter_next)(&local_10), cVar2 != '\0') {
      cVar2 = ovl_set_iter_current_is_visible_non_instance(&local_10);
      if (cVar2 != '\0') {
        pcVar3 = ovl_set_iter_current_symbol(&local_10);
        bVar5 = (pcVar3->flags2 & 3) != 1;
        pcVar3 = ovl_set_iter_current_symbol(&local_10);
        *ctor_count = *ctor_count + (uint)((pcVar3->flags1 & 0x10) == 0x10);
        pcVar3 = ovl_set_iter_current_symbol(&local_10);
        *assign_count = *assign_count + (uint)(pcVar3->name == g_name_operator_assign);
        pcVar3 = (c1_symbol *)&local_10.current[-1].position;
        if ((local_10.current[-1].position & 0x1f) == 0x1a) {
          pcVar3 = (((local_10.current)->type).alias)->target;
        }
        if ((*(byte *)((int)&pcVar3->tail + 8) & 0x10) != 0) {
          states[9] = '\x01';
          if (states[10] != '\0') {
            if (states[0xc] == '\0') {
              diag_warning(3,0x208,cls);
            }
            states[0xc] = '\x01';
          }
          states[0xb] = states[0xb] & bVar5;
          states[10] = '\x01';
        }
        pcVar3 = (c1_symbol *)&local_10.current[-1].position;
        bVar1 = (byte)local_10.current[-1].position & 0x1f;
        pcVar4 = pcVar3;
        if (bVar1 == 0x1a) {
          pcVar4 = (((local_10.current)->type).alias)->target;
        }
        if ((*(byte *)((int)&pcVar4->tail + 8) & 0x20) == 0) {
          pcVar4 = pcVar3;
          if (bVar1 == 0x1a) {
            pcVar4 = (((local_10.current)->type).alias)->target;
          }
          if ((*(byte *)((int)&pcVar4->tail + 8) & 0x80) == 0) {
            if (bVar1 == 0x1a) {
              pcVar3 = (((local_10.current)->type).alias)->target;
            }
            if ((pcVar3->flags1 & 0x20) == 0x20) {
              states[0x1e] = '\x01';
              if (states[0x1f] != '\0') {
                if (states[0x21] == '\0') {
                  diag_warning(3,0x20b,cls);
                }
                states[0x21] = '\x01';
              }
              states[0x20] = states[0x20] & bVar5;
              states[0x1f] = '\x01';
            }
          }
          else {
            states[0x17] = '\x01';
            if (states[0x18] != '\0') {
              if (states[0x1a] == '\0') {
                diag_warning(3,0x20a,cls);
              }
              states[0x1a] = '\x01';
            }
            states[0x19] = states[0x19] & bVar5;
            states[0x18] = '\x01';
            pcVar3 = ovl_set_iter_current_symbol(&local_10);
            ((cls->detail).cls)->pm_model =
                 (*(byte *)((int)&pcVar3->tail + 10) & 0xe0) << 1 |
                 ((cls->detail).cls)->pm_model & 0x3f;
          }
        }
        else {
          states[0x10] = '\x01';
          if (states[0x11] != '\0') {
            if (states[0x13] == '\0') {
              diag_warning(3,0x209,cls);
            }
            states[0x13] = '\x01';
          }
          states[0x12] = states[0x12] & bVar5;
          states[0x11] = '\x01';
          pcVar3 = ovl_set_iter_current_symbol(&local_10);
          ((cls->detail).cls)->pm_model =
               *(byte *)((int)&pcVar3->tail + 10) >> 1 & 0x30 | ((cls->detail).cls)->pm_model & 0xcf
          ;
        }
      }
    }
    cVar2 = class_member_iter_next(&local_28);
    if (cVar2 == '\0') break;
    sym_overload_iter_init(&local_10,local_28.current);
  }
  return;
}

