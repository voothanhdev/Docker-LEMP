<?php
return [
    'queue'                => [
        'amqp'                        => [
            'host'        => 'rabbit',
            'port'        => '5672',
            'user'        => 'guest',
            'password'    => 'guest',
            'virtualhost' => '/'
        ],
        'consumers_wait_for_messages' => 1
    ],
    'backend'              => [
        'frontName' => 'adm'
    ],
    'crypt'                => [
        'key' => '4311eed0838025b4fd91b889db6630e0'
    ],
    'db'                   => [
        'table_prefix' => '',
        'connection'   => [
            'default' => [
                'host'           => 'db',
                'dbname'         => 'local',
                'username'       => 'root',
                'password'       => 'local',
                'model'          => 'mysql4',
                'engine'         => 'innodb',
                'initStatements' => 'SET NAMES utf8;',
                'active'         => '1',
                'driver_options' => [
                    1014 => false
                ]
            ]
        ]
    ],
    'resource'             => [
        'default_setup' => [
            'connection' => 'default'
        ]
    ],
    'x-frame-options'      => 'SAMEORIGIN',
    'MAGE_MODE'            => 'developer',
    'session'              => [
        'save'  => 'redis',
        'redis' => [
            'host'                     => 'redis',
            'port'                     => '6379',
            'password'                 => '',
            'timeout'                  => '2.5',
            'persistent_identifier'    => '',
            'database'                 => '2',
            'compression_threshold'    => '2048',
            'compression_library'      => 'gzip',
            'log_level'                => '4',
            'max_concurrency'          => '6',
            'break_after_frontend'     => '5',
            'break_after_adminhtml'    => '30',
            'first_lifetime'           => '600',
            'bot_first_lifetime'       => '60',
            'bot_lifetime'             => '7200',
            'disable_locking'          => '0',
            'min_lifetime'             => '60',
            'max_lifetime'             => '2592000',
            'sentinel_master'          => '',
            'sentinel_servers'         => '',
            'sentinel_connect_retries' => '5',
            'sentinel_verify_master'   => '0'
        ]
    ],
    'cache'                => [
        'frontend' => [
            'default'    => [
                'id_prefix'       => '40d_',
                'backend'         => 'Cm_Cache_Backend_Redis',
                'backend_options' => [
                    'server'          => 'redis',
                    'database'        => '0',
                    'port'            => '6379',
                    'password'        => '',
                    'compress_data'   => '1',
                    'compression_lib' => ''
                ]
            ],
            'page_cache' => [
                'id_prefix'       => '40d_',
                'backend'         => 'Cm_Cache_Backend_Redis',
                'backend_options' => [
                    'server'          => 'redis',
                    'database'        => '1',
                    'port'            => '6379',
                    'password'        => '',
                    'compress_data'   => '0',
                    'compression_lib' => ''
                ]
            ]
        ]
    ],
    'lock'                 => [
        'provider' => 'db',
        'config'   => [
            'prefix' => ''
        ]
    ],
    'cache_types'          => [
        'config'                 => 1,
        'layout'                 => 1,
        'block_html'             => 1,
        'collections'            => 1,
        'reflection'             => 1,
        'db_ddl'                 => 1,
        'compiled_config'        => 1,
        'eav'                    => 1,
        'customer_notification'  => 1,
        'config_integration'     => 1,
        'config_integration_api' => 1,
        'google_product'         => 1,
        'full_page'              => 1,
        'config_webservice'      => 1,
        'translate'              => 1,
        'vertex'                 => 1
    ],
    'downloadable_domains' => [
        'magento2.test'
    ],
    'install'              => [
        'date' => 'Fri, 08 May 2020 02:28:37 +0000'
    ],
    'system' => [
        'default' => [
            'catalog' => [
                'search' => [
                    'elasticsearch7_server_hostname' => 'elasticsearch',
                    'elasticsearch7_server_port'     => '9200',
                    'elasticsearch7_index_prefix'    => 'local',
                ],
            ],
        ],
    ],
];