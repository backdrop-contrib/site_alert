<?php

/**
 *  BlockHero extends BlockText
 *
 *  This class allows us to create site alert blocks.
 */
class BlockSiteAlert extends BlockText {

  /**
   * {@inheritdoc}
   */
  function __construct($plugin_name, array $data) {
    parent::__construct($plugin_name, $data);

    $this->settings += [
      'severity' => '',
    ];
  }

  /**
   *  Sets title text on draggable block panel in Layout builder.
   */
  function getAdminTitle() {
    if (!empty($this->settings['admin_label'])) {
      return check_plain($this->settings['admin_label']);
    }

    return !empty($this->settings['title']) ? check_plain(
      $this->settings['title']
    ) : t('Site Alert block');
  }

  /**
   * Returns the rendered content of this block.
   *
   * If there is no content, a non-breaking space is returned to ensure the
   * block is still displayed, with only the background image applied.
   *
   * @return string
   */
  function getContent() {
    $path = backdrop_get_path('module', 'site_alert');
    backdrop_add_css($path . '/css/site-alert.css');
    $level = ($this->settings['severity']);
    $output = '<div class="site-alert">' ;
    $output .= '<div class="' . $level .'"><div class="text">';
    $output .= ($this->settings['content']);
    $output .= '</div></div></div>';


    return $output;
  }

  /**
   *  Builds the block's configuration form.
   */
  function form(&$form, &$form_state) {
    parent::form($form, $form_state);

    $form['severity'] = array(
      '#type'          => 'select',
      '#title'         => t('Severity'),
      '#options'       => array(
        'info' => t('Informational Only - Default Blue'),
        'low'  => t('Low Severity - Default Yellow'),
        'high' => t('High Severity - Default Red'),
      ),
      '#default_value' => $this->settings['severity'],
      '#required'      => TRUE,
    );


    // Disable reusable until a later date.
    $form['convert']['#access'] = FALSE;
  }

  /**
   * Validates the form settings.
   */
  /* function formValidate($form, &$form_state) {
     parent::formValidate($form, $form_state);

     // Check that one of title, text, or image, is provided.
     if (empty($form_state['values']['video']) && empty($form_state['values']['title']) && empty($form_state['values']['content']['value'])) {
       form_error($form['image'], t('Background video, a Display title, or Block content must be provided.'));
     }
   }*/

  /**
   * Submit handler to save the form settings.
   */
  function formSubmit($form, &$form_state) {
    parent::formSubmit($form, $form_state);

    // Save the things not handled by BlockText.
    if (!empty($form_state['values']['severity'])) {
      if ($form_state['values']['severity']
        != $form['severity']['#default_value']
      ) {
        $this->settings['severity']
          = $form_state['values']['severity'];
      }
    }
  }

}


