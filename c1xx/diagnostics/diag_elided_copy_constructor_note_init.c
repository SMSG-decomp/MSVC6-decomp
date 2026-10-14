c1xx_obj_104cb248 * __thiscall
diag_elided_copy_constructor_note_init
          (c1xx_obj_104cb248 *note,c1_type *from,c1_type *to,c1_symbol *ctor)

{
  note[1].vtbl = (c1xx_vtbl_104cb248 *)from;
  note[2].vtbl = (c1xx_vtbl_104cb248 *)to;
  note[3].vtbl = (c1xx_vtbl_104cb248 *)ctor;
  note->vtbl = (c1xx_vtbl_104cb248 *)&PTR_diag_note_elided_copy_constructor_104cb248;
  return note;
}

