# Docker compose for LEMP

## Basic Installation

My DockerLEMP is installed by running one of the following commands in your terminal.
You can install this via the command-line with either `curl`, `wget` or another similar tool.

| Method    | Command                                                                                           |
| :-------- | :------------------------------------------------------------------------------------------------ |
| **curl**  | `sh -c "$(curl -fsSL https://raw.githubusercontent.com/voothanhdev/Docker-LEMP/master/install)"` |
| **wget**  | `sh -c "$(wget -O- https://raw.githubusercontent.com/voothanhdev/Docker-LEMP/master/install)"`   |
| **fetch** | `sh -c "$(fetch -o - https://raw.githubusercontent.com/voothanhdev/Docker-LEMP/master/install)"` |

Restart your device after it's installed.


## Useful commands
- `init-doco`: Init docker-compose file.
- `doco`: docker-compose alias.
- `create-project`: Setup new project.
- `composer`: composer command on php service. (Ex: composer install).
- `php-service`: Docker compose php service alias (docker-compose exec php ...).
- `php-enable`: Enable php module(s).
- `php-disable`: Disable php module(s).
- `pconfig`: Update PHP config on `/usr/local/etc/php/conf.d/zz-docker.ini` (Ex: pconfig max_input_vars=100000 memory_limit=8G).
- `ppool`: Update FPM pool config on `/usr/local/etc/php-fpm.d/zz-docker.conf` (Ex: ppool pm.max_children=40).
- `php`: PHP command on php service (Ex: php -v).
- `redis-cli`: redis-cli command on redis service.
- `mgt`: Magento n98 (Ex: mgt cache:flush).
- `magento`: Run the Magento CLI (Ex: magento cache:flush).
- `magento-patches`: Run the magento patches command.
- `init-magento-env`: Init magento env.php file.
- `mysql-import`: Import database.
- `mysql-export`: Export database.
- `permission`: Fix permission.
- `clean-docker-volume`: Clean docker volume
- `clean-docker-image`: Clean docker image no name
- `clean-docker-container`: Clean docker container

### Image command
#### Nginx
- `vhost`: Create new vhost
  - `vhost -h`: Command description
  - You can create new vhost in Docker Compose by adding `vhost` command to the `command` option of the `nginx` service
  <pre>
  command:
        - vhost --folder= \
                --server-name= \
                --https= \
                --varnish-host= \
                --project-type= \
                --varnish-port= \
                --proxy-host= \
                --proxy-port=
        - vhost --folder= \
                --server-name= \
                --https= \
                --varnish-host= \
                --project-type= \
                --varnish-port= \
                --proxy-host= \
                --proxy-port=
        ...
  </pre>
#### PHP
- `cron-start`: Start cron tab service
- `download-n98`: Download n98 command for Magento
- `optimize-composer1`: Install composer package `hirak/prestissimo`


## Email / Mailhog
View emails sent locally through Mailhog by visiting http://localhost:8025

## Elastic Search
You can access elastic search index via: http://localhost:9200/.

## RabbitMQ
You can access via: http://localhost:15672 . Default user/pass: guest/guest.


