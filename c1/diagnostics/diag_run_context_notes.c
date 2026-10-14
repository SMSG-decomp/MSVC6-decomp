void __fastcall diag_run_context_notes(fe_diag_context *list)

{
  fe_diag_note_cell *pfVar1;
  
  for (pfVar1 = list->context_notes; pfVar1 != (fe_diag_note_cell *)0x0; pfVar1 = pfVar1->next) {
    (*pfVar1->object->vtbl->note)();
    diag_queue_release_pending(list);
  }
  return;
}

