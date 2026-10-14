void __fastcall emit_symbol_definition(c2_fe_symbol *s,uint32_t offset)

{
  uint32_t uVar1;
  char *pcVar2;
  char *pcVar3;
  uint uVar4;
  c2_fe_symbol *pcVar5;
  
  uVar4 = s->attrs;
  if (((uVar4 & 0x10000) == 0) &&
     ((((s->flags31 & 4) != 0 ||
       ((s->cls == '\x01' &&
        ((((byte)s->storage & 0x70) == 0x30 ||
         ((((byte)s->storage & 0x70) == 0x10 &&
          (((uVar4 & 0x800) != 0 || ((s->storage & 0x8000) != 0)))))))))) ||
      ((s->cls == '\x03' && (g_opt_global == 0)))))) {
    if ((s->cls == '\x01') && (s->name == (char *)0x0)) {
      if (((g_opt_cbstring != 0) && ((uVar4 & 0x600) == 0x600)) &&
         ((pcVar5 = fe_symbol_lookup_id(s->section_id), pcVar5 != (c2_fe_symbol *)0x0 &&
          ((pcVar5->u44).section_class == '\0')))) {
LAB_10753230:
        cv_emit_unnamed_ldata32_symbol(s);
        return;
      }
    }
    else {
      switch(s->cls) {
      case '\x01':
        if ((*s->name != '?') ||
           (((pcVar3 = fe_symbol_name(s,0), pcVar3 != (char *)0x0 && (*pcVar3 != '\0')) &&
            (pcVar3 = strchr(pcVar3,0x60), pcVar3 == (char *)0x0)))) {
          if (g_symdef_storage_class == 0) {
            g_symdef_storage_class = s->storage >> 7 & 0xf;
          }
          if ((s->role == '\0') || (s->role == '$')) {
            if (s->cls == '\x01') {
              uVar4 = s->storage;
              if (((uVar4 & 0x70) == 0x10) || ((uVar4 & 0x70) == 0x30)) {
                if ((uVar4 & 0x8000) == 0) {
                  cv_emit_bprel32_symbol(s);
                  g_symdef_storage_class = 0;
                  return;
                }
                if (((byte)uVar4 & 0xf) == 6) {
                  g_symdef_storage_class = 0;
                  return;
                }
                cv_emit_register_symbol(s);
                g_symdef_storage_class = 0;
                return;
              }
            }
            if ((g_symdef_storage_class == 4) &&
               (((uVar4 = s->storage & 0x70, uVar4 == 0x60 || (uVar4 == 0x20)) || (uVar4 == 0x40))))
            {
              cv_emit_ldata32_symbol(s,offset);
              g_symdef_storage_class = 0;
              return;
            }
            cv_emit_gdata32_symbol(s,offset);
          }
          g_symdef_storage_class = 0;
          return;
        }
        break;
      case '\x03':
        if (s->role != '\0') {
          if (s->role == '\x02') goto LAB_10753230;
          if ((*(byte *)&s->u3e & 1) == 0) {
            return;
          }
        }
        cv_emit_label32_symbol(s);
        return;
      case '\a':
        pcVar5 = fe_symbol_lookup_id(s->refcount);
        pcVar5->flags31 = pcVar5->flags31 | 4;
        pcVar5->attrs = pcVar5->attrs & 0xfffeffff;
        (*g_hook_emit_symbol_once)(pcVar5);
        uVar4 = s->storage;
        uVar1 = pcVar5->cv_type_index;
        pcVar3 = s->name;
        pcVar2 = pcVar5->name;
        pcVar5->cv_type_index = s->cv_type_index;
        pcVar5->name = pcVar3;
        g_symdef_storage_class = uVar4 >> 7 & 0xf;
        emit_symbol_definition(pcVar5,s->offset + offset);
        pcVar5->name = pcVar2;
        pcVar5->cv_type_index = uVar1;
        pcVar5->attrs = pcVar5->attrs | 0x10000;
        g_symdef_storage_class = 0;
        return;
      case '\b':
        cv_emit_constant_symbol(s);
        break;
      case '\v':
        cv_emit_udt_symbol(s);
        return;
      }
    }
  }
  return;
}

