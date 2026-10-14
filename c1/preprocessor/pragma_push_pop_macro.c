int __cdecl pragma_push_pop_macro(int code)

{
  char *s;
  c1_pushed_macro *pcVar1;
  uchar *puVar2;
  c1_pushed_macro **ppcVar3;
  c1_token *pcVar4;
  fe_name *pfVar5;
  c1_pushed_macro *pcVar6;
  fe_macro *old_definition;
  
  pcVar4 = pragma_warn_expected_token('v');
  if ((pcVar4 != (c1_token *)0x0) && (pcVar4 = pragma_string_argument(), pcVar4 != (c1_token *)0x0))
  {
    s = (pcVar4->value).string.text;
    pcVar4 = pragma_warn_expected_token('~');
    if (pcVar4 != (c1_token *)0x0) {
      if (((s == (char *)0x0) || (*s == '\0')) ||
         (pfVar5 = name_intern(s), pfVar5 == (fe_name *)0x0)) {
        diag_warning(1,600);
        return 0;
      }
      if (code == 0x38) {
        if (pfVar5->macro == (fe_macro *)0x0) {
          diag_warning(1,0x259,pfVar5);
        }
        pcVar6 = (c1_pushed_macro *)g_arenas[0].cur;
        g_arenas[0].cur = g_arenas[0].cur + 0x10;
        if (g_arenas[0].end < g_arenas[0].cur) {
          arena_grow(g_arenas);
        }
        if (pcVar6 == (c1_pushed_macro *)0x0) {
          pcVar6 = (c1_pushed_macro *)0x0;
        }
        else {
          old_definition = pfVar5->macro;
          pcVar6->name = pfVar5;
          *(fe_macro **)((int)pcVar6 + 4) = old_definition;
          *(uchar *)((int)pcVar6 + 8) = '\0';
          *(uchar *)((int)pcVar6 + 9) = '\0';
          *(uchar *)((int)pcVar6 + 10) = '\0';
          *(uchar *)((int)pcVar6 + 0xb) = '\0';
          *(uchar *)((int)pcVar6 + 0xc) = '\0';
          *(uchar *)((int)pcVar6 + 0xd) = '\0';
          *(uchar *)((int)pcVar6 + 0xe) = '\0';
          *(uchar *)((int)pcVar6 + 0xf) = '\0';
        }
        puVar2 = g_arenas[0].cur;
        if (g_pushed_macros == (c1_pushed_macro **)0x0) {
          g_arenas[0].cur = g_arenas[0].cur + 4;
          if (g_arenas[0].end < g_arenas[0].cur) {
            arena_grow(g_arenas);
          }
          if (puVar2 == (uchar *)0x0) {
            g_pushed_macros = (c1_pushed_macro **)0x0;
          }
          else {
            puVar2[0] = '\0';
            puVar2[1] = '\0';
            puVar2[2] = '\0';
            puVar2[3] = '\0';
            g_pushed_macros = (c1_pushed_macro **)puVar2;
          }
        }
        ppcVar3 = g_pushed_macros;
        if (*g_pushed_macros != (c1_pushed_macro *)0x0) {
          pcVar6->next = *g_pushed_macros;
          (*ppcVar3)->prev = pcVar6;
        }
        *ppcVar3 = pcVar6;
        return 0;
      }
      if (g_pushed_macros != (c1_pushed_macro **)0x0) {
        pcVar6 = *g_pushed_macros;
        if (pcVar6 != (c1_pushed_macro *)0x0) {
          while (pcVar6->name != pfVar5) {
            pcVar6 = pcVar6->next;
            if (pcVar6 == (c1_pushed_macro *)0x0) {
              diag_warning(1,0x25a,pfVar5);
              return 0;
            }
          }
          if (pcVar6 != (c1_pushed_macro *)0x0) {
            pfVar5->macro = pcVar6->definition;
            for (pcVar1 = *g_pushed_macros; (pcVar1 != (c1_pushed_macro *)0x0 && (pcVar1 != pcVar6))
                ; pcVar1 = pcVar1->next) {
            }
            if (pcVar1->prev == (c1_pushed_macro *)0x0) {
              *g_pushed_macros = pcVar1->next;
            }
            else {
              pcVar1->prev->next = pcVar1->next;
            }
            if (pcVar1->next == (c1_pushed_macro *)0x0) {
              return 0;
            }
            pcVar1->next->prev = pcVar1->prev;
            return 0;
          }
        }
        diag_warning(1,0x25a,pfVar5);
        return 0;
      }
      diag_warning(1,0x25a,pfVar5);
      return 0;
    }
  }
  return 0;
}

